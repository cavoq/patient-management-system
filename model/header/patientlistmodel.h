ifndef PATIENTLISTMODEL_H
#define PATIENTLISTMODEL_H

#include <QAbstractListModel>

class PatientListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PatientListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // PATIENTLISTMODEL_H
