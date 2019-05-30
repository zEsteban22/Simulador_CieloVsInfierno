#ifndef CONSULTARMUNDO_H
#define CONSULTARMUNDO_H
#include <QMainWindow>
#include <QTableWidget>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QDialog>

namespace Ui {
class ConsultarMundo;
}

class ConsultarMundo : public QDialog
{
		Q_OBJECT

	public:
		explicit ConsultarMundo(QWidget *parent = nullptr);
        ~ConsultarMundo();

	private:
		Ui::ConsultarMundo *ui;
};

#endif // MAINWINDOW_H
