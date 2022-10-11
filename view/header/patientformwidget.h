#ifndef PATIENTFORMWIDGET_H
#define PATIENTFORMWIDGET_H

#include <QWidget>

namespace Ui {
class PatientFormWidget;
}

class PatientFormWidget : public QWidget
{
    Q_OBJECT

public slots:
    void discard();
    bool verify();

public:
    explicit PatientFormWidget(QWidget *parent = nullptr);
    ~PatientFormWidget();
    Ui::PatientFormWidget *ui;
};

#endif // PATIENTFORMWIDGET_H
