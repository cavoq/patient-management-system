#ifndef CHANGEPATIENTWIDGET_H
#define CHANGEPATIENTWIDGET_H

#include <QWidget>
#include "view/header/patientformwidget.h"
#include "model/header/patienttablemodel.h"

namespace Ui {
class ChangePatientWidget;
}

class ChangePatientWidget : public PatientFormWidget
{
    Q_OBJECT

public slots:
    void discard();
    void accept();

public:
    explicit ChangePatientWidget(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr, const QModelIndexList &selectionIndexes = QModelIndexList());
    ~ChangePatientWidget();
};

#endif // CHANGEPATIENTWIDGET_H
