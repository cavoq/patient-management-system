/**
 *  Declaration of the MultiColumnFilterProxyModel, used to filter multiple columns in a TableView.
 *  @see TableView
 */

#ifndef MULTICOLUMNFILTERPROXYMODEL_H
#define MULTICOLUMNFILTERPROXYMODEL_H

#include "qdatetime.h"
#include <QSortFilterProxyModel>

class MultiColumnFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public slots:

    /**
     * Slot that updated {@link #firstNameSearchString} and triggers the filter.
     * @param searchString String {@link #firstNameSearchString} will be set to.
     */
    void setFirstNameFilter(const QString &searchString);

    /**
     * Slot that updated {@link #nameSearchString} and triggers the filter.
     * @param searchString String {@link #nameSearchString} will be set to.
     */
    void setNameFilter(const QString &searchString);

    /**
     * Slot that updated {@link #birthDateSearchString} and triggers the filter.
     * @param searchString String {@link #birthDateSearchString} will be set to.
     */
    void setBirthDateFilter(const QString &searchString);

public:

    /**
     * Constructs a new MultiColumnFilterProxyModel object.
     *
     * @param parent Parent widget of the proxy model.
     */
    explicit MultiColumnFilterProxyModel(QObject *parent = nullptr);

    /**
     * Checks if the row is acceptable.
     *
     * @param sourceRow Row to be checked.
     * @param sourceParent QModelIndex of the parent.
     * @return Returns true if {@link #firstNameSearchString}, {@link #nameSearchString}, {@link #birthDateSearchString} are
     * each contained in the corresponding column of the sourceRow.
     */
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:

    /// First name string to be contained.
    QString firstNameSearchString;

    /// Name string to be contained.
    QString nameSearchString;

    /// Birth date string to be contained.
    QString birthDateSearchString;
};

#endif // MULTICOLUMNFILTERPROXYMODEL_H
