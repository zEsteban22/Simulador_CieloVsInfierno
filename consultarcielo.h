#ifndef CONSULTARCIELO_H
#define CONSULTARCIELO_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class ConsultarCielo : public QDialog
{
        Q_OBJECT

    public:
        explicit ConsultarCielo(QWidget *parent = nullptr);
        ~ConsultarCielo();

    private slots:
        void on_pushButton_clicked();

        void on_spinBox_valueChanged(const QString &arg1);

    private:
        Ui::Dialog *ui;
};

#endif // MAINWINDOW_H
