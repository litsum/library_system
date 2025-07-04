#include "ai_progress.h"
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "librarydatabase.h"
#include "database.h"
#include <QCoreApplication>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QFile>
#include <QByteArray>

#include <QApplication>


//用于向api发送网络请求
NetworkRequestWrapper::NetworkRequestWrapper(QObject* parent) : QObject(parent), manager(new QNetworkAccessManager(this)) {}

QString NetworkRequestWrapper::sendRequest(const QString& user_input) {
    // 创建请求
    QNetworkRequest request(QUrl("https://api.siliconflow.cn/v1/chat/completions"));

    // 设置请求头,用于身份认证
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer sk-saowyhmyzudeatectmrnnuvalxvoevsdtysiyimsvlrdyhdb");

    // 将用户输入合并到上下文，准备向api请求数据
    QByteArray jsonData = prepareJsonData(user_input);
    qDebug() << "等待大模型响应......";
    // 发送 POST 请求
    QNetworkReply* reply = manager->post(request, jsonData);

    // 等待请求完成
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // 检查请求是否成功
    if (reply->error() == QNetworkReply::NoError) {
        // 解析响应数据
        QByteArray responseData = reply->readAll();
        QString decodedResponse = QString::fromUtf8(responseData);
        QString content = extractContent(decodedResponse);
        return content;
    } else {
        // 请求失败
        qDebug() << "[Error]网络请求失败：" << reply->errorString();
    }
    reply->deleteLater(); // 删除返回的reply 对象
    return QString();
}

QByteArray NetworkRequestWrapper::prepareJsonData(const QString& user_input) {
    // 创建 JSON 数据
    QJsonArray messagesArray;
    {
        QString booklist = "目前图书馆里有下列书籍:";
        for (auto i =db.books.begin();i!=db.books.end();++i)
        {
            booklist += i->getName();
            booklist += ",";
        }
        QString prompt= "##Role：图书管理系统中的自然语言处理模块  #系统规则 - 请解析用户输入的自然语言，分析实现用户需求所需要调用的功能，并转化成返回给程序接口的固定指令 #回复格式 - 每次只能调用一个功能 - 严格按照以下格式进行回复，不能输出任何额外内容 [自然语言回复用户][要调用的功能序号][传给该功能的参数值] #功能列表以下内容按照“序号：功能类型[返回值类型：需要生成的内容]（解释说明）”的格式给出 0:处理错误 参数值[string：error_type]（没有找到明确的功能对应） 1:借书 参数值[string：bookname] 2:还书 参数值[string：bookname] 3:查看借阅记录 不返回参数值4:查看图书推荐 不返回参数值";
        QString example ="#示例用户输入：我想借一本老人与海 你的回复：[好的,我已经把你的借阅信息记录到了系统中，这本书以简洁有力的笔触描绘了人类与命运抗争的精神史诗，展现坚韧力量与不屈灵魂，阅读它就是接受一场心灵的洗礼，希望你读的愉快][1][老人与海]";
        QString system_prompt =prompt+booklist+example;
        //系统提示词部分
        QJsonObject messages;
        messages["role"] = "system";
        messages["content"] = system_prompt;
        messagesArray.append(messages);
    }

    {
        //将用户输入追加到历史上下文
        QJsonObject userMessage;
        userMessage["role"] = "user";
        userMessage["content"] = user_input;
        messagesArray.append(userMessage);
    }

    //模型调用参数，参考siliconflow给出的api手册
    QJsonObject requestObj;
    requestObj["model"] = "deepseek-ai/DeepSeek-V2.5";
    requestObj["stream"] = false;
    requestObj["max_tokens"] = 512;
    requestObj["enable_thinking"] = true;
    requestObj["thinking_budget"] = 4096;
    requestObj["min_p"] = 0.05;
    requestObj["temperature"] = 0.7;
    requestObj["top_p"] = 0.7;
    requestObj["top_k"] = 50;
    requestObj["frequency_penalty"] = 0.5;
    requestObj["n"] = 1;
    requestObj["stop"] = QJsonArray();
    requestObj["messages"] = messagesArray;

    // 将 JSON 对象转换为字节数组以发送
    QJsonDocument doc(requestObj);
    return doc.toJson(QJsonDocument::Compact);
}

QString NetworkRequestWrapper::extractContent(const QString& decodedResponse) {
    // 解析 JSON 数据，获取llm返回的指令性语言
    QJsonDocument jsonDoc = QJsonDocument::fromJson(decodedResponse.toUtf8());
    if (!jsonDoc.isNull() && jsonDoc.isObject()) {
        QJsonObject jsonObj = jsonDoc.object();

        // 提取 choices 数组
        QJsonValue choicesValue = jsonObj.value("choices");
        if (choicesValue.isArray()) {
            QJsonArray choicesArray = choicesValue.toArray();
            if (!choicesArray.isEmpty()) {
                // 获取第一个 choice 对象
                QJsonObject firstChoice = choicesArray.first().toObject();

                // 提取 message 对象
                QJsonValue messageValue = firstChoice.value("message");
                if (messageValue.isObject()) {
                    QJsonObject messageObj = messageValue.toObject();

                    // 提取 content 字段
                    QJsonValue contentValue = messageObj.value("content");
                    if (contentValue.isString()) {
                        return contentValue.toString();
                    }
                }
            }
        }
    }
    return QString();
}
//用于向api发送语音转文本请求

#include <QApplication>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

QNetworkAccessManager *manager;

QString getTranscription(const QString &file_path)
{
    manager = new QNetworkAccessManager();

    QFile file(file_path);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return QString();
    }

    QByteArray audio_data = file.readAll();
    file.close();
    QString api_key = "sk-saowyhmyzudeatectmrnnuvalxvoevsdtysiyimsvlrdyhdb";
    QString url = "http://api.siliconflow.cn/v1/audio/transcriptions"; // 替换为实际的 URL

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "multipart/form-data; boundary=---------------------------boundary");
    request.setRawHeader("accept", "application/json");
    request.setRawHeader("authorization", ("Bearer " + api_key).toUtf8());

    QByteArray boundary = "---------------------------boundary";
    QByteArray body;

    body.append("--" + boundary + "\r\n");
    body.append("Content-Disposition: form-data; name=\"model\"\r\n");
    body.append("\r\n");
    body.append("FunAudioLLM/SenseVoiceSmall\r\n");

    body.append("--" + boundary + "\r\n");
    body.append("Content-Disposition: form-data; name=\"file\"; filename=\"do_stt.wav\"\r\n");
    body.append("Content-Type: audio/mpeg\r\n");
    body.append("\r\n");
    body.append(audio_data + "\r\n");

    body.append("--" + boundary + "--\r\n");

    QNetworkReply *reply = manager->post(request, body);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Network request failed:" << reply->errorString();
        reply->deleteLater();
        return QString();
    }

    QByteArray response_data = reply->readAll();
    reply->deleteLater();

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    if (json_doc.isNull()) {
        qDebug() << "Failed to parse JSON response";
        return QString();
    }

    QJsonObject json_obj = json_doc.object();
    return json_obj.value("text").toString();
}
