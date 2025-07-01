#include "admcontrol.h"
#include "ui_admcontrol.h"
#include "book.h"
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include <QMenu>
#include <QComboBox>
#include "find.h"

admcontrol::admcontrol(QWidget *parent)
    : QDialog(parent), ui(new Ui::admcontrol), _model(new QStandardItemModel(this))
{
    ui->setupUi(this);
    refreshBookTable();

    _model->setHorizontalHeaderLabels({"ISBN", "书名", "作者","出版社","状态"});

    //下拉选择
    ui->comboBox->addItem("哲学");
    ui->comboBox->addItem("艺术");
    ui->comboBox->addItem("自然科学");
    ui->comboBox->addItem("社会科学");
    ui->comboBox->addItem("教育");
    ui->comboBox->addItem("文学");
    // 可选：设置搜索列
    ui->searchBox->addItem("ISBN", 0);
    ui->searchBox->addItem("书名", 1);
    ui->searchBox->addItem("作者", 2);
    ui->searchBox->addItem("出版社", 3);

    // 关联到视图4
    BookSearchProxyModel *proxyModel = new BookSearchProxyModel(this);
    proxyModel->setSourceModel(_model);
    ui->tableView_2->setModel(proxyModel);
    ui->tableView_2->setSortingEnabled(true);

    // 连接搜索框
    connect(ui->name_2, &QLineEdit::textChanged,
            [proxyModel](const QString &text) {
                proxyModel->setSearchPrefix(text);
            });
    connect(ui->searchBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [proxyModel](int index) {
                proxyModel->setSearchColumn(index);
            });
    connect(ui->searchBox,QOverload<int>::of(&QComboBox::currentIndexChanged),this,
            &admcontrol::textchange);

    //右键点击功能
    ui->tableView_2->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView_2, &QTableView::customContextMenuRequested, [this, proxyModel](const QPoint &pos){
        QMenu menu;
        QAction *deleteAction = menu.addAction("删除图书");
        if (deleteAction == menu.exec(ui->tableView_2->viewport()->mapToGlobal(pos))) {
            QModelIndex index = ui->tableView_2->indexAt(pos);
            if (index.isValid()) {
                // 映射到源模型索引
                QModelIndex sourceIndex = proxyModel->mapToSource(index);
                if (sourceIndex.isValid()) {
                    QString name = _model->item(sourceIndex.row(), 1)->text();
                    if (db.deletebook(name)) {
                        _model->removeRow(sourceIndex.row());
                        QMessageBox::information(this, "成功", "图书已删除");
                    } else {
                        QMessageBox::warning(this, "错误", "删除图书失败");
                    }
                }
            }
        }
    });

}
admcontrol::~admcontrol()
{
    delete ui;
}

void admcontrol::refreshBookTable()
{
    _model->removeRows(0, _model->rowCount());

    int row = 0;
    for(auto is = db.books.begin(); is != db.books.end(); ++is) {
        QList<QStandardItem*> rowItems;

        // ISBN
        QString isbn = QString::fromStdString(is->getISBN());
        QStandardItem *isbnItem = new QStandardItem(isbn);
        isbnItem->setEditable(false);

        // 书名
        QString name = QString::fromStdString(is->getName());
        QStandardItem *nameItem = new QStandardItem(name);

        // 作者
        QString author = QString::fromStdString(is->getAuthor());
        QStandardItem *authorItem = new QStandardItem(author);

        // 出版社
        QString publisher = QString::fromStdString(is->getPublisher());
        QStandardItem *publisherItem = new QStandardItem(publisher);

        // 状态
        QStandardItem *statusItem = new QStandardItem();
        statusItem->setCheckable(true);
        statusItem->setCheckState(is->isAvailable() ? Qt::Checked : Qt::Unchecked);
        statusItem->setText(is->isAvailable() ? "可借阅" : "已借出");
        statusItem->setEditable(false);

        rowItems << isbnItem << nameItem << authorItem << publisherItem << statusItem;
        _model->appendRow(rowItems);
        row++;
    }
}

void admcontrol::on_pushButton_clicked()
{
    QString name = ui->name_1->text().toUtf8();
    QString author = ui->author->text();
    QString publisher = ui->publisher->text();
    QString isbn = ui->resultLabel->text();

    if (name.isEmpty() || author.isEmpty() || publisher.isEmpty() || isbn=="请选择类别：") {
        QMessageBox::warning(this, "错误", "请填写所有字段！");
        return;
    }
    Book newBook(name.toStdString(), author.toStdString(), publisher.toStdString(),isbn.toStdString());
    db.books.push_back(newBook);
    QMessageBox::information(this, "成功", "书籍添加成功！");
    ui->name_1->clear();
    ui->author->clear();
    ui->publisher->clear();
    refreshBookTable();
}


void admcontrol::textchange(int index){
    switch (index) {
    case 0:
        ui->name_2->setPlaceholderText("ISBN:");
        break;
    case 1:
        ui->name_2->setPlaceholderText("书名:");
        break;
    case 2:
        ui->name_2->setPlaceholderText("作者:");
        break;
    case 3:
        ui->name_2->setPlaceholderText("出版社:");
        break;
    default:
        break;
    }
}

void admcontrol::on_comboBox_activated(int index)
{
    QString text = ui->comboBox->itemText(index);
    QString result = QString("%1").arg(text);
    ui->resultLabel->setText(result);
}

