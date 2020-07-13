#include "newrecord.h"
#include "ui_newrec.h"

NewRecord::NewRecord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewRecord)
{
    ui->setupUi(this);
}

NewRecord::~NewRecord()
{
    delete ui;
}

void NewRecord::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
