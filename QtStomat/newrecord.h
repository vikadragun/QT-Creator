#ifndef NEWRECORD_H
#define NEWRECORD_H

#include <QWidget>

namespace Ui {
class NewRecord;
}

class NewRecord : public QWidget
{
    Q_OBJECT

public:
    explicit NewRecord(QWidget *parent = 0);
    ~NewRecord();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();

private:
    Ui::NewRecord *ui;
};

#endif // NEWRECORD_H
