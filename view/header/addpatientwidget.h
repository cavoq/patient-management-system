#ifndef ADDPATIENTWIDGET_H
#define ADDPATIENTWIDGET_H

#include <QWidget>

namespace Ui {
class AddPatientWidget;
}

class AddPatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddPatientWidget(QWidget *parent = nullptr);
    ~AddPatientWidget();

private:
    Ui::AddPatientWidget *ui;
};

#endif // ADDPATIENTWIDGET_H
