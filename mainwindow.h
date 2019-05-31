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
		QPushButton*getBoton();
		QPushButton*getBoton2();
		QPushButton*getBoton3();
};

#endif // MAINWINDOW_H
