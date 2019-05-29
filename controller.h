#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "infierno.h"
#include "mundo.h"
#include "paraiso.h"
//#include <../SmtpClient-for-Qt/src/SmtpMime>
#include <QMessageBox>
#include <QString>


struct Controller
{
		Mundo mundo;
		Infierno infierno;
		Paraiso paraiso;
		void mandarAlInfierno(){
			enviarCorreo(infierno.condenar(mundo));
		}
		void salvarPersonas(){
			paraiso.salvarHumanos(&infierno);
		}
		void enviarCorreo(string mensaje);
		Controller();
};

#endif // CONTROLLER_H
