#include "form1.h"
#include "ui_form1.h"

#include <QMessageBox>
#include <QSqlError>


Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    setWindowIcon(QIcon(":/C:/qtlab/curswork/QtStomat/icon.png"));
    ui->setupUi(this);
    model = new QSqlQueryModel;
    QPixmap bkgnd("C:\\qtlab\\curswork\\QtStomat\\bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Form1::~Form1()
{
    delete ui;
}

void Form1::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}


void Form1::on_pushButton_clicked(){

    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "" && ui->lineEdit_4->text() != ""){
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setUserName("root");
        db.setDatabaseName("dentistry");
        db.setPassword("1304");
        db.setHostName("localhost");
        db.setPort(3306);

         if(db.open()){
        QString str1 = ui->lineEdit->text();
        QString str2 = ui->lineEdit_2->text();
        QString str3 = ui->lineEdit_3->text();
        QString str4 = ui->lineEdit_4->text();

        int s1 = str1.toInt();


        qry = new QSqlQuery(db);
        qry->prepare("INSERT INTO doctors(id,name,spec,stage) VALUES(:id,:name,:spec,:stage);");
        qry->bindValue(":id",s1);
        qry->bindValue(":name",str2);
        qry->bindValue(":spec",str3);
        qry->bindValue(":stage",str4);

        QMessageBox* mess = new QMessageBox();
        if(!qry->exec())
        {
            mess->setText("Запрос составлен неверно :(");
            mess->show();
        }

    }
    }
    this->close();
    emit refresh_table();
    emit firstWindow();
}
