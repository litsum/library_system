#ifndef AI_PROGRESS_H
#define AI_PROGRESS_H
#ifndef NETWORKREQUESTWRAPPER_H
#define NETWORKREQUESTWRAPPER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>

class NetworkRequestWrapper : public QObject {
    Q_OBJECT

public:
    explicit NetworkRequestWrapper(QObject* parent = nullptr);
    QString sendRequest(const QString& user_input);

private:
    QNetworkAccessManager* manager;
    QByteArray prepareJsonData(const QString& user_input);
    QString extractContent(const QString& decodedResponse);
};


QString getTranscription(const QString &file_path);

#endif // NETWORKREQUESTWRAPPER_H
#endif // AI_PROGRESS_H
