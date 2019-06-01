#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "infierno.h"
#include "mundo.h"
#include "cielo.h"
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

struct Controller:public QObject
{
		Q_OBJECT
		Mundo mundo;
		Infierno infierno;
		Cielo cielo;
		ConsultarCielo cc;
		ConsultarInfierno ci;
		ConsultarMundo cm;
		MainWindow mw;
		void enviarCorreo(string mensaje);
		QString qStringGanador(int i, int j);
		void makeConnections();
		QVector<QPair<Persona*,string>>getTodosLosDeLaFamilia(string apellido,string pais);
		void porcentajeFamiliaVivaVsCieloVsInfierno(string apellido,string pais);
		void todasLasPersonasApellidoPais(string apellido,string pais);
		QVector<QPair<Persona*,string>> listadoPersonas(bool pecados,string filtro,string tipoFiltro);
	public:
		void start(){
			mw.showNormal();
		}
		Controller();
		virtual ~Controller(){}
	public slots:
		void ganador();
		void mandarAlInfierno();
		void salvarPersonas();
		void abrirVentanaInfierno();
		void abrirVentanaMundo();
		void abrirVentanaParaiso();
		void volverALaPrincipal();
};

#endif // CONTROLLER_H
