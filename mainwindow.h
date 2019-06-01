#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = nullptr);
		~MainWindow();

		Ui::MainWindow *ui;
        QPushButton*getConsultarInfierno();
        QPushButton*getConsultarCielo();
        QPushButton*getConsultarMundo();
        QPushButton*getGanador();


};

#endif // MAINWINDOW_H
