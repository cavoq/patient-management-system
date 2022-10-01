#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QWidget>

namespace Ui {
class DeleteDialog;
}

class DeleteDialog : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteDialog(QWidget *parent = nullptr);
    ~DeleteDialog();

private:
    Ui::DeleteDialog *ui;
};

#endif // DELETEDIALOG_H
