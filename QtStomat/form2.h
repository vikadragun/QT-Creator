#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = 0);
     void connectToSql();
    ~Form2();
signals:
    void firstWindow();
    void refresh_table();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::Form2 *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQuery *qry;
};

#endif // FORM2_H
