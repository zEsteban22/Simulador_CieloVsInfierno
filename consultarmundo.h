#ifndef CONSULTARMUNDO_H
#define CONSULTARMUNDO_H
#include <QMainWindow>
#include <QTableWidget>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QDialog>

namespace Ui {
class Dialog;
}

class ConsultarMundo : public QDialog
{
		Q_OBJECT

	public:
		explicit ConsultarMundo(QWidget *parent = nullptr);
        ~ConsultarMundo();


	private slots:
		void on_pushButton_clicked();

		void on_spinBox_valueChanged(const QString &arg1);

        void on_spinBox_valueChanged(int arg1);

        void on_doubleSpinBox_valueChanged(double arg1);

private:
		Ui::Dialog *ui;
};

#endif // MAINWINDOW_H
