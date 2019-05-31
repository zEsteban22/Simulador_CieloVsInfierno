#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "infierno.h"
#include "mundo.h"
#include "paraiso.h"
#include <SMTPEmail/src/SmtpMime>
#include <QMessageBox>
#include <QString>
#include "consultarcielo.h"
#include "consultarinfierno.h"
#include "consultarmundo.h"
#include "mainwindow.h"

struct comparaPersona {
		bool pecados;
		comparaPersona(bool p):pecados(p){}
		bool operator()(QPair<Persona*,string>const&e1,QPair<Persona*,string>const&e2);
};

struct Controller:QObject
{
		Mundo mundo;
		Infierno infierno;
		Paraiso paraiso;
		ConsultarCielo cc;
		ConsultarInfierno ci;
		ConsultarMundo cm;
		MainWindow mw;
		void mandarAlInfierno();
		void salvarPersonas();
		void enviarCorreo(string mensaje);
		QString qStringGanador(int i, int j);
		void ganador();
		void makeConnections(){
			connect(mw.getBoton(),SIGNAL(clicked()),this,SLOT(abrirVentanaInfierno()));
			connect(mw.getBoton2(),SIGNAL(clicked()),this,SLOT(abrirVentanaCielo()));
			connect(mw.getBoton3(),SIGNAL(clicked()),this,SLOT(abrirVentanaInfierno()));

		}
		QVector<QPair<Persona*,string>>getTodosLosDeLaFamilia(string apellido,string pais);
		void porcentajeFamiliaVivaVsCieloVsInfierno(string apellido,string pais);
		void todasLasPersonasApellidoPais(string apellido,string pais);
		QVector<QPair<Persona*,string>> listadoPersonas(bool pecados,string filtro,string tipoFiltro);
		Controller():mundo(),infierno(),paraiso(),cc(),ci(),cm(){
			cc.setModal(1);
			ci.setModal(1);
			cm.setModal(1);
			cc.exec();
			ci.exec();
			cm.exec();
			cc.hide();
			ci.hide();
			cm.hide();
			mw.show();
		}
		Q_OBJECT
	public slots:
		void abrirVentanaInfierno(){
			mw.hide();
			ci.show();
		}
		void abrirVentanaMundo(){
			mw.hide();
			cm.show();
		}
		void abrirVentanaParaiso(){
			mw.hide();
			cc.show();
		}
		void volverALaPrincipal(){
			cc.hide();
			ci.hide();
			cm.hide();
			mw.show();
		}
};

#endif // CONTROLLER_H
