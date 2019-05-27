#ifndef MAPACONDEGRADACIONDECOLOR_H
#define MAPACONDEGRADACIONDECOLOR_H

#include <QWidget>

namespace Ui {
class MapaConDegradacionDeColor;
}

class MapaConDegradacionDeColor : public QWidget
{
		Q_OBJECT

	public:
		explicit MapaConDegradacionDeColor(int africa,int america,int europa,int asia,int oceania,QWidget *parent = nullptr);
		~MapaConDegradacionDeColor();

	private:
		Ui::MapaConDegradacionDeColor *ui;
};

#endif // MAPACONDEGRADACIONDECOLOR_H
