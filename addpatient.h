#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QWidget>

namespace Ui {
class addPatient;
}

class addPatient : public QWidget
{
    Q_OBJECT

public:
    explicit addPatient(QWidget *parent = nullptr);
    ~addPatient();

private:
    Ui::addPatient *ui;
};

#endif // ADDPATIENT_H
