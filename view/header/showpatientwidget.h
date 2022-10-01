#ifndef SHOWPATIENTWIDGET_H
#define SHOWPATIENTWIDGET_H

#include <QWidget>

namespace Ui {
class ShowPatientWidget;
}

class ShowPatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowPatientWidget(QWidget *parent = nullptr);
    ~ShowPatientWidget();

private:
    Ui::ShowPatientWidget *ui;
};

#endif // SHOWPATIENTWIDGET_H
