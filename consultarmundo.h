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

		Ui::ConsultarMundo *ui;
        QPushButton*getInsertaPersona();
        QPushButton*getVolver();
        QPushButton*getPecarObrar();
        QPushButton*getEstadoPecados();
        QPushButton*getPaisesPecadores();
        QPushButton*getPaisesMenosPecadores();
        QPushButton*getMapaDegradacionPecados();
        QPushButton*getPaisesVirtuosos();
        QPushButton*getMenosVirtuosos();
        QPushButton*getMapaDecradacionVirtudes();
        QSpinBox*getSpinboxInsertarPersona();
        QSpinBox*getSpinboxInsertarID();

};

#endif // MAINWINDOW_H
