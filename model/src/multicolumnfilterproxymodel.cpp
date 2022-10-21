#include "model/header/multicolumnfilterproxymodel.h"

MultiColumnFilterProxyModel::MultiColumnFilterProxyModel(QObject *parent) : QSortFilterProxyModel(parent) {}

bool MultiColumnFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex firstNameIndex = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex nameIndex = sourceModel()->index(sourceRow, 2, sourceParent);
    QModelIndex birthDateIndex = sourceModel()->index(sourceRow, 3, sourceParent);

    QString firstName = sourceModel()->data(firstNameIndex).toString();
    QString name = sourceModel()->data(nameIndex).toString();
    QString birthDate = sourceModel()->data(birthDateIndex).toString();

    return (firstName.contains(firstNameSearchString) && name.contains(nameSearchString) && birthDate.contains(birthDateSearchString));
}

void MultiColumnFilterProxyModel::setFirstNameFilter(const QString &searchString)
{
    firstNameSearchString = searchString;
    invalidateFilter();
}

void MultiColumnFilterProxyModel::setNameFilter(const QString &searchString)
{
    nameSearchString = searchString;
    invalidateFilter();
}

void MultiColumnFilterProxyModel::setBirthDateFilter(const QString &searchString)
{
    birthDateSearchString = searchString;
    invalidateFilter();
}
