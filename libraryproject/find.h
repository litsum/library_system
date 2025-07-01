#ifndef FIND_H
#define FIND_H
#include <QSortFilterProxyModel>

class BookSearchProxyModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    explicit BookSearchProxyModel(QObject *parent = nullptr);

    void setSearchPrefix(const QString &prefix);
    void setSearchColumn(int column);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString m_prefix;
    int m_searchColumn = 1; // 默认在书名列搜索
};

#endif // FIND_H
