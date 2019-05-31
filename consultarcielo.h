#ifndef CONSULTARCIELO_H
#define CONSULTARCIELO_H

#include <QDialog>

namespace Ui {
class ConsultarCielo;
}

class ConsultarCielo : public QDialog
{
        Q_OBJECT

    public:
        explicit ConsultarCielo(QWidget *parent = nullptr);
        ~ConsultarCielo();

		Ui::ConsultarCielo *ui;
};

#endif // MAINWINDOW_H
