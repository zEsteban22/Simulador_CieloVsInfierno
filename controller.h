#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "infierno.h"
#include "mundo.h"
#include "paraiso.h"



struct Controller
{
		Mundo mundo;
		Infierno infierno;
		Paraiso paraiso;
		void mandarAlInfierno(){
			infierno.condenar(mundo);
		}
		Controller();
};

#endif // CONTROLLER_H
