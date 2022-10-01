#ifndef CHANGEPATIENTWIDGET_H
#define CHANGEPATIENTWIDGET_H

#include <QWidget>

namespace Ui {
class ChangePatientWidget;
}

class ChangePatientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePatientWidget(QWidget *parent = nullptr);
    ~ChangePatientWidget();

private:
    Ui::ChangePatientWidget *ui;
};

#endif // CHANGEPATIENTWIDGET_H
