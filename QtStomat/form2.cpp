#include "form2.h"
#include "ui_form2.h"

#include <QMessageBox>
#include <QSqlError>


Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{

    ui->setupUi(this);
    model = new QSqlQueryModel;
    setWindowIcon(QIcon(":/C:/qtlab/curswork/QtStomat/icon.png"));
    QPixmap bkgnd("C:\\qtlab\\curswork\\QtStomat\\bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

Form2::~Form2()
{
    delete ui;
}

void Form2::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}


void Form2::on_pushButton_clicked(){

    if(ui->lineEdit->text() != "" && ui->lineEdit_2->text() != "" && ui->lineEdit_3->text() != ""){
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

        int s1 = str1.toInt();
        int s3 = str3.toInt();


        qry = new QSqlQuery(db);
        qry->prepare("INSERT INTO services(id,name,cost) VALUES(:id,:name,:cost);");
        qry->bindValue(":id",s1);
        qry->bindValue(":name",str2);
        qry->bindValue(":cost",s3);

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
