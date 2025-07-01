#include "find.h"

BookSearchProxyModel::BookSearchProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent) {}

void BookSearchProxyModel::setSearchPrefix(const QString &prefix) {
    m_prefix = prefix;
    invalidateFilter();
}

void BookSearchProxyModel::setSearchColumn(int column) {
    m_searchColumn = column;
    invalidateFilter();
}

bool BookSearchProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const {
    if (m_prefix.isEmpty()) return true;

    QModelIndex index = sourceModel()->index(source_row, m_searchColumn, source_parent);
    QString data = sourceModel()->data(index).toString();

    return data.startsWith(m_prefix, Qt::CaseInsensitive);
}
