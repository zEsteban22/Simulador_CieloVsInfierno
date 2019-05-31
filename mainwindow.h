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
        QPushButton*getBoton();//consultar infierno
        QPushButton*getBoton2();//consultar cielo
        QPushButton*getBoton3();//consultar mundo
        QPushButton*getBoton4();//ganador


};

#endif // MAINWINDOW_H
