#ifndef CONSULTARINFIERNO_H
#define CONSULTARINFIERNO_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class ConsultarInfierno : public QDialog
{
		Q_OBJECT

	public:
        explicit ConsultarInfierno(QWidget *parent = nullptr);
        ~ConsultarInfierno();

	private slots:
		void on_pushButton_clicked();

		void on_spinBox_valueChanged(const QString &arg1);

	private:
		Ui::Dialog *ui;
};

#endif // MAINWINDOW_H
