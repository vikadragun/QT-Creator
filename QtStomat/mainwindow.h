#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "form.h"
#include "form1.h"
#include "form2.h"
#include "informdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void connectToSql();
    ~MainWindow();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void obr_ref_tabs();

    void on_action_triggered();

private:

    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    QSqlQuery *qry;

    QSqlQueryModel *model2;
    QSqlQuery *qry2;

    QSqlQueryModel *model3;
    QSqlQuery *qry3;

    QString table;
    QSqlQueryModel *model4;
     QSqlQuery *qry4;
    Form *newrec;
    Form1 *newrec1;
    Form2 *newrec2;
    InformDialog *infD;
};

#endif // MAINWINDOW_H
