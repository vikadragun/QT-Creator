#include "informdialog.h"
#include "ui_informdialog.h"

#include <QFile>
#include <QTextBrowser>
#include <QTextStream>
#include <QStyle>

InformDialog::InformDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InformDialog)
{
    ui->setupUi(this);
   /* QString line;
    QFile inf("C:\\qtlab\\curswork\\QtStomat\\Inform.txt");
    if(!inf.open(QIODevice::ReadOnly))
          return;

    QTextStream stream(&inf);
        QString str = stream.readAll();
        ui->textBrowser->setText(str);
        inf.close();
*/
       QFile file("C:\\qtlab\\curswork\\QtStomat\\mainPage.html");
       file.open(QIODevice::ReadOnly | QIODevice::Text);
       ui->textBrowser->setHtml(file.readAll());
        setWindowIcon(QIcon(":/C:/qtlab/curswork/QtStomat/icon.png"));
        QPixmap bkgnd("C:\\qtlab\\curswork\\QtStomat\\bg.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

}

InformDialog::~InformDialog()
{
    delete ui;
}

void InformDialog::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
