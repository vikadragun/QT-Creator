#include "form.h"
#include "ui_form.h"

#include <QMessageBox>
#include <QSqlError>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/C:/qtlab/curswork/QtStomat/icon.png"));
    model = new QSqlQueryModel;
    connectToSql();
    QPixmap bkgnd("C:\\qtlab\\curswork\\QtStomat\\bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void Form::connectToSql()
{

}

void Form::on_pushButton_2_clicked(){

    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != "" && ui->lineEdit_4->text() != "" && ui->lineEdit_5->text() != ""){
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
        QString str5 = ui->lineEdit_5->text();

        int s1 = str1.toInt();
       // int s3 = str3.toInt();
        //int s4 = str4.toInt();

        qry = new QSqlQuery(db);
        qry->prepare("INSERT INTO medicalrec(id,name,doc,serv,date) VALUES(:id,:name,:doc,:serv,:date);");
        qry->bindValue(":id",s1);
        qry->bindValue(":name",str2);
        qry->bindValue(":doc",str3);
        qry->bindValue(":serv",str4);
        qry->bindValue(":date",str5);

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
