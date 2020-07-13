#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
     void connectToSql();
    ~Form();
signals:
    void firstWindow();
    void refresh_table();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::Form *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQuery *qry;
};

#endif // FORM_H
