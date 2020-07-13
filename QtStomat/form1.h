#ifndef FORM1_H
#define FORM1_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = 0);
     void connectToSql();
    ~Form1();
signals:
    void firstWindow();
    void refresh_table();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::Form1 *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQuery *qry;
};

#endif // FORM1_H
