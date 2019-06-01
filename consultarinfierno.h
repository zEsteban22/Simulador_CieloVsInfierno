#ifndef CONSULTARINFIERNO_H
#define CONSULTARINFIERNO_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class ConsultarInfierno;
}

class ConsultarInfierno : public QDialog
{
		Q_OBJECT

	public:
        explicit ConsultarInfierno(QWidget *parent = nullptr);
        ~ConsultarInfierno();

		Ui::ConsultarInfierno *ui;
		QPushButton*getVolver();
		QPushButton*getCondenar();
		virtual void closeEvent(QCloseEvent*e){
			e->ignore();
			emit cerrar();
		}
	signals:
		void cerrar();
};

#endif // MAINWINDOW_H
