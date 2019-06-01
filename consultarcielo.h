#ifndef CONSULTARCIELO_H
#define CONSULTARCIELO_H

#include <QDialog>
#include <QCloseEvent>

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
		QPushButton*getVolver();
		QPushButton*SalvarHumanos();
		virtual void closeEvent(QCloseEvent*e){
			e->ignore();
			emit cerrar();
		}
	signals:
		void cerrar();
};

#endif // MAINWINDOW_H
