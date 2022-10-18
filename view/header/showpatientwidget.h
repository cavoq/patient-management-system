#ifndef SHOWPATIENTWIDGET_H
#define SHOWPATIENTWIDGET_H

#include "model/header/patienttablemodel.h"
#include "view/header/patientformwidget.h"
#include <QWidget>

namespace Ui {
class ShowPatientWidget;
}

class ShowPatientWidget : public PatientFormWidget
{
    Q_OBJECT

public:
    explicit ShowPatientWidget(QWidget *parent = nullptr, PatientTableModel *patientTableModel = nullptr, const QModelIndexList &selectionIndexes = QModelIndexList());
    ~ShowPatientWidget();

private:
    void setEditable(bool editable);
};

#endif // SHOWPATIENTWIDGET_H
