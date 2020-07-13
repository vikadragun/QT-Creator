#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QSqlError>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newrec = new Form();
    newrec1 = new Form1();
    newrec2 = new Form2();
    infD = new InformDialog();
    model = new QSqlQueryModel;
    model2 = new QSqlQueryModel;
    model3 = new QSqlQueryModel;
    model4 = new QSqlQueryModel;
    connectToSql();
    connect(newrec, &Form::firstWindow, this,&MainWindow::show);
    connect(newrec1, &Form1::firstWindow, this,&MainWindow::show);
    connect(newrec2, &Form2::firstWindow, this,&MainWindow::show);
    connect(infD, &InformDialog::firstWindow, this,&MainWindow::show);

       QPixmap bkgnd("C:\\qtlab\\curswork\\QtStomat\\bg.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);
       setWindowIcon(QIcon(":/C:/qtlab/curswork/QtStomat/icon.png"));

   }

void MainWindow::connectToSql()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setUserName("root");
    db.setDatabaseName("dentistry");
    db.setPassword("1304");
    db.setHostName("localhost");
    db.setPort(3306);

    if(db.open()){
        qry = new QSqlQuery(db);
        qry->prepare("select * from doctors");
        qry->exec();

        model->setQuery(*qry);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model->setHeaderData(0,Qt::Horizontal,tr("Code"));
        model->setHeaderData(1,Qt::Horizontal,tr("Name"));
        model->setHeaderData(2,Qt::Horizontal,tr("Specialty"));
        model->setHeaderData(3,Qt::Horizontal,tr("Experience"));

        qry2 = new QSqlQuery(db);
        qry2->prepare("select * from services");
        qry2->exec();

        model2->setQuery(*qry2);
        ui->tableView_2->setModel(model2);
        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model2->setHeaderData(0,Qt::Horizontal,tr("Code"));
        model2->setHeaderData(1,Qt::Horizontal,tr("Name"));
        model2->setHeaderData(2,Qt::Horizontal,tr("Cost"));


        qry3 = new QSqlQuery(db);
        qry3->prepare("select * from medicalrec");
        qry3->exec();

        model3->setQuery(*qry3);
        ui->tableView_3->setModel(model3);
        ui->tableView_3->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        model3->setHeaderData(0,Qt::Horizontal,tr("Code"));
        model3->setHeaderData(1,Qt::Horizontal,tr("Name"));
        model3->setHeaderData(2,Qt::Horizontal,tr("Doctor's code"));
        model3->setHeaderData(3,Qt::Horizontal,tr("Sevice's code"));
        model3->setHeaderData(4,Qt::Horizontal,tr("Date"));

    }
    else {
        QMessageBox::critical(this,"Error",model->lastError().text());
    }
}

MainWindow::~MainWindow()
{
    delete model;
    delete qry;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    connect(newrec,SIGNAL(refresh_table()),this,SLOT(obr_ref_tabs()));
    newrec->show();
   // this->close();
}
void MainWindow::on_pushButton_2_clicked()
{

    connect(newrec1,SIGNAL(refresh_table()),this,SLOT(obr_ref_tabs()));
    newrec1->show();
   // this->close();
}
void MainWindow::on_pushButton_3_clicked()
{

    connect(newrec2,SIGNAL(refresh_table()),this,SLOT(obr_ref_tabs()));
    newrec2->show();
   // this->close();
}
void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox* mess = new QMessageBox();
    QMessageBox::StandardButton bYes;

    bYes = QMessageBox::question(this,"Delete service","Are you sure about that?",QMessageBox::Yes|QMessageBox::No);
    if(bYes == QMessageBox::Yes){
        QSqlQuery qry1;
        QString name = model2->data(model2->index(ui->tableView_2->currentIndex().row(),1),Qt::DisplayRole).toString();
        //if (table == "services"){
      //  if(db.open()){
            qry1.prepare("select id from services where name = :name;");
            qry1.bindValue(":name",name);

            mess->setText(name);
            mess->show();

            if(qry1.exec()){
                qry1.next();
                int id = qry1.value(0).toInt();

               // qry1.prepare("delete from medicalrec where serv_id = :id;");
                qry1.prepare("update medicalrec set serv='0' where serv = :name;");
                qry1.bindValue(":name",name);
                qry1.exec();

                //mess->setText("из карточки удалена услуга");
              //  mess->show();

                if(qry1.exec()){
                    qry1.prepare("delete from services where id = :id;");
                    qry1.bindValue(":id",id);
                    qry1.exec();

                  //  mess->setText("из списка услуг удалена услуга");
                   // mess->show();
                }
            }
       // }
      //  else{
          //   QMessageBox::critical(this,"Error",model->lastError().text());
       // }

        qry2->exec();
        model2->setQuery(*qry2);
        ui->tableView_2->setModel(model2);


        qry3->exec();
        model3->setQuery(*qry3);
        ui->tableView_3->setModel(model3);
       // connectToSql();
    }
}

void MainWindow::on_pushButton_5_clicked()
{

    QMessageBox* mess = new QMessageBox();
    qry4 = new QSqlQuery(db);
    QString name = model->data(model->index(ui->tableView->currentIndex().row(),1),Qt::DisplayRole).toString();
    QString doc_id = model->data(model->index(ui->tableView->currentIndex().row(),0),Qt::DisplayRole).toString();
    int idoc_id = doc_id.toInt();

    qry4->prepare("select name, serv, date from medicalrec where doc = :name;");
    qry4->bindValue(":name",name);
    qry4->exec();

    ui->lineEdit->setText(name);
    model4->setQuery(*qry4);
    ui->tableView_4->setModel(model4);
    ui->tableView_4->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    model4->setHeaderData(0,Qt::Horizontal,tr("Name"));
    model4->setHeaderData(1,Qt::Horizontal,tr("Service"));
    model4->setHeaderData(2,Qt::Horizontal,tr("Date"));

}
void MainWindow::obr_ref_tabs()
{
    connectToSql();
}


void MainWindow::on_action_triggered()
{
    connect(infD,SIGNAL(),this,SLOT());
    infD->show();

}
