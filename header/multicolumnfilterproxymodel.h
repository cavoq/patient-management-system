#ifndef MULTICOLUMNFILTERPROXYMODEL_H
#define MULTICOLUMNFILTERPROXYMODEL_H

#include "qdatetime.h"
#include <QSortFilterProxyModel>

class MultiColumnFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT


public slots:
    void setFirstNameFilter(const QString &searchString);
    void setNameFilter(const QString &searchString);
    void setBirthDateFilter(const QString &searchString);

public:
    explicit MultiColumnFilterProxyModel(QObject *parent = nullptr);
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QString firstNameSearchString;
    QString nameSearchString;
    QString birthDateSearchString;
};

#endif // MULTICOLUMNFILTERPROXYMODEL_H
