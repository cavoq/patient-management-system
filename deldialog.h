#ifndef DELDIALOG_H
#define DELDIALOG_H

#include <QWidget>

namespace Ui {
class delDialog;
}

class delDialog : public QWidget
{
    Q_OBJECT

public:
    explicit delDialog(QWidget *parent = nullptr);
    ~delDialog();

private:
    Ui::delDialog *ui;
};

#endif // DELDIALOG_H
