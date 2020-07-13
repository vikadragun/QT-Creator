#ifndef INFORMDIALOG_H
#define INFORMDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QDebug>

namespace Ui {
class InformDialog;
}

class InformDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InformDialog(QWidget *parent = nullptr);
    ~InformDialog();
signals:
    void firstWindow();
private slots:
    void on_pushButton_clicked();
private:
    Ui::InformDialog *ui;
};

#endif // INFORMDIALOG_H
