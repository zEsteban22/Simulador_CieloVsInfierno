#ifndef CONSULTARINFIERNO_H
#define CONSULTARINFIERNO_H

#include <QDialog>

namespace Ui {
class ConsultarInfierno;
}

class ConsultarInfierno : public QDialog
{
		Q_OBJECT

	public:
        explicit ConsultarInfierno(QWidget *parent = nullptr);
        ~ConsultarInfierno();

	private:
		Ui::ConsultarInfierno *ui;
};

#endif // MAINWINDOW_H
