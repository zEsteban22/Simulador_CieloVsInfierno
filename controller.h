#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "infierno.h"
#include "mainwindow.h"
#include "mundo.h"
#include "paraiso.h"



struct Controller
{
		Mundo mundo;
		Infierno infierno;
		Paraiso paraiso;
		MainWindow mw;
		void mandarAlInfierno(){
			infierno.condenar(mundo);
		}
		void salvarPersonas(){
			paraiso.salvarHumanos(&infierno);
		}
		Controller();
};

#endif // CONTROLLER_H
