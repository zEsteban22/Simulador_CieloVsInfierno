#include "controller.h"

void Controller::mandarAlInfierno(){
	enviarCorreo(infierno.condenar(mundo));
}

void Controller::salvarPersonas(){
	enviarCorreo(cielo.salvarHumanos(infierno));
}

void Controller::enviarCorreo(string mensaje){

	SmtpClient smtp("smtp.gmail.com", 587, SmtpClient::TlsConnection);

	smtp.setUser("cuentanivelbajo@gmail.com");
	smtp.setPassword("esteBan2203");

	MimeMessage message;

	EmailAddress sender("cuentanivelbajo@gmail.com", "Yo:3");
	message.setSender(&sender);

	EmailAddress to("xllestebanllx@gmail.com", "Primoxd");
	message.addRecipient(&to);

	message.setSubject("Log");

	MimeText text;

	text.setText(QString::fromStdString(mensaje));

	message.addPart(&text);

	if (!smtp.connectToHost())
		QMessageBox(QMessageBox::Critical,QString("Error"),
								QString("No se ha podido conectar al host"),QMessageBox::Ok).exec();
	if (!smtp.login())
		QMessageBox(QMessageBox::Critical,QString("Error"),
								QString("No se ha podido iniciar sesión"),QMessageBox::Ok).exec();
	if (!smtp.sendMail(message))
		QMessageBox(QMessageBox::Critical,QString("Error"),
								QString("No se ha podido enviar el correo"),QMessageBox::Ok).exec();

	smtp.quit();

}

QString Controller::qStringGanador(int i, int j){
	if (i<j)
		return "Cielo";
	else if (j<i)
		return "Infierno";
	else return "Empate!";
}

void Controller::ganador(){
	int**accionesInfierno=infierno.sumaAcciones();
	int**accionesParaiso=cielo.sumaAcciones();
	for(int i=0;i<7;i++){
		QMessageBox(QMessageBox::Information,QString::fromStdString("Info ganador "+mundo.tiposPecados[i]+" vs "+mundo.tiposVirtudes[i]),
								"Cantidad pecado infierno: "+QString::number(accionesInfierno[0][i])+"\nCantidad virtud infierno: "+QString::number(accionesInfierno[1][i])+
				"\nNeto infierno: "+QString::number(accionesInfierno[0][i]-accionesInfierno[1][i])+
				"\nCantidad pecado cielo: "+QString::number(accionesParaiso[0][i])+"\nCantidad virtud cielo: "+QString::number(accionesParaiso[1][i])+
				"\nNeto cielo: "+QString::number(accionesParaiso[1][i]-accionesParaiso[0][i])+"\nGanador: "+qStringGanador(accionesInfierno[0][i]-accionesInfierno[1][i],accionesParaiso[1][i]-accionesParaiso[0][i]));
	}
}

void Controller::makeConnections(){
	connect(mw.getConsultarInfierno(),SIGNAL(clicked()),this,SLOT(abrirVentanaInfierno()));
	connect(mw.getConsultarCielo(),SIGNAL(clicked()),this,SLOT(abrirVentanaParaiso()));
	connect(mw.getConsultarMundo(),SIGNAL(clicked()),this,SLOT(abrirVentanaMundo()));
	connect(mw.getGanador(),SIGNAL(clicked()),this,SLOT(ganador()));
	connect(cc.getVolver(),SIGNAL(clicked()),this,SLOT(volverALaPrincipal()));
	connect(cm.getVolver(),SIGNAL(clicked()),this,SLOT(volverALaPrincipal()));
	connect(ci.getVolver(),SIGNAL(clicked()),this,SLOT(volverALaPrincipal()));
	connect(&cc,SIGNAL(cerrar()),this,SLOT(volverALaPrincipal()));
	connect(&cm,SIGNAL(cerrar()),this,SLOT(volverALaPrincipal()));
	connect(&ci,SIGNAL(cerrar()),this,SLOT(volverALaPrincipal()));
}



QVector<QPair<Persona*, string> > Controller::getTodosLosDeLaFamilia(string apellido, string pais){
	QVector<QPair<Persona*,string>>salida;
	nodoPersona*p=mundo.familiasPorPais[QString::fromStdString(pais)][QString::fromStdString(apellido)].r;
	QQueue<nodoPersona*>restantes;
	while(p!=nullptr||!restantes.empty()){
		if(p!=nullptr){
			restantes.enqueue(p->l);
			restantes.enqueue(p->r);
			salida.insert(upper_bound(salida.begin(),salida.end(),QPair<Persona*,string>(p->d,"mundo"),comparaPersona(true)),QPair<Persona*,string>(p->d,"mundo"));
		}
		p=restantes.dequeue();
	}
	for (int i=0;i<7;i++){
		for(QPair<QString,avlFamilia>nodo:infierno.familiasPorPecado[i]){
			if (nodo.first.toStdString()==apellido+"-"+pais){
				p=nodo.second.r;
				break;
			}
		}
		while(p!=nullptr||!restantes.empty()){
			if(p!=nullptr){
				restantes.enqueue(p->l);
				restantes.enqueue(p->r);
				salida.insert(upper_bound(salida.begin(),salida.end(),QPair<Persona*,string>(p->d,"infierno"),comparaPersona(true)),QPair<Persona*,string>(p->d,"infierno"));
			}
			p=restantes.dequeue();
		}
	}
	QQueue<NodoAngel*>restantesCielo;
	NodoAngel*angel=cielo.arbolDeAngeles.dios;
	while(angel!=nullptr){
		restantesCielo.enqueue(angel->hijo1);
		restantesCielo.enqueue(angel->hijo2);
		restantesCielo.enqueue(angel->hijo3);
		if (angel->persona!=nullptr){
			for(int j=0;j<7;j++){
				if(angel->persona->apellido==apellido&&pais==angel->persona->pais)
					salida.insert((upper_bound(salida.begin(),salida.end(),QPair<Persona*,string>(angel->persona,"cielo"),comparaPersona(true))),QPair<Persona*,string>(angel->persona,"cielo"));
			}
		}
		angel=restantesCielo.dequeue();
	}
	return salida;
}

void Controller::porcentajeFamiliaVivaVsCieloVsInfierno(string apellido, string pais){
	QVector<QPair<Persona*,string>>familiaCompleta=getTodosLosDeLaFamilia(apellido,pais);
	QMap<string,int>cantApariciones;
	QMap<string,double>porcentaje;
	for(QPair<Persona*,string>p:familiaCompleta){
		cantApariciones[p.second]++;
	}
	porcentaje["cielo"]=cantApariciones["cielo"]/(double)familiaCompleta.size();
	porcentaje["infierno"]=cantApariciones["infierno"]/(double)familiaCompleta.size();
	porcentaje["mundo"]=cantApariciones["mundo"]/(double)familiaCompleta.size();
	//return porcentaje;
}

void Controller::todasLasPersonasApellidoPais(string apellido, string pais){
	QVector<QPair<Persona*,string>>porApellido=listadoPersonas(true,apellido,"apellido");
	QVector<QPair<Persona*,string>>porPais=listadoPersonas(true,pais,"pais");
	string text="";
	for(QPair<Persona*,string>p:porPais){
		if (porApellido.contains(p)){
			text+="Miembro localizado en: "+p.second+"\n"+p.first->to_string();
		}
	}
}

QVector<QPair<Persona*, string> > Controller::listadoPersonas(bool pecados, string filtro, string tipoFiltro){
	QVector<QPair<Persona*,string>>lista;
	for (NodoLista*temp=mundo.lista.primero();temp!=nullptr;temp=temp->siguiente)
		if((tipoFiltro=="apellido"?temp->persona->apellido:tipoFiltro=="pais"?temp->persona->pais:tipoFiltro=="creencia"?temp->persona->creencia:temp->persona->profesion)==filtro)
			lista.insert((upper_bound(lista.begin(),lista.end(),QPair<Persona*,string>(temp->persona,"mundo"),comparaPersona(pecados))),QPair<Persona*,string>(temp->persona,"mundo"));
	nodoPersona*persona;
	for(int i=0;i<7;i++)
		for(QPair<QString,avlFamilia> familia:infierno.familiasPorPecado[i]){
			QQueue<nodoPersona*>restantes;
			persona=familia.second.r;
			while(persona!=nullptr||!restantes.isEmpty()){
				if (persona!=nullptr){
					restantes.enqueue(persona->l);
					restantes.enqueue(persona->r);
					for(int j=0;j<7;j++){
						if((tipoFiltro=="apellido"?persona->d->apellido:tipoFiltro=="pais"?persona->d->pais:tipoFiltro=="creencia"?persona->d->creencia:persona->d->profesion)==filtro)
							lista.insert((upper_bound(lista.begin(),lista.end(),QPair<Persona*,string>(persona->d,"infierno"),comparaPersona(pecados))),QPair<Persona*,string>(persona->d,"infierno"));
					}
				}
				persona=restantes.dequeue();
			}
		}
	QQueue<NodoAngel*>restantes;
	NodoAngel*angel=cielo.arbolDeAngeles.dios;
	while(angel!=nullptr){
		restantes.enqueue(angel->hijo1);
		restantes.enqueue(angel->hijo2);
		restantes.enqueue(angel->hijo3);
		if (angel->persona!=nullptr){
			for(int j=0;j<7;j++){
				if((tipoFiltro=="apellido"?angel->persona->apellido:tipoFiltro=="pais"?angel->persona->pais:tipoFiltro=="creencia"?angel->persona->creencia:angel->persona->profesion)==filtro)
					lista.insert((upper_bound(lista.begin(),lista.end(),QPair<Persona*,string>(angel->persona,"cielo"),comparaPersona(pecados))),QPair<Persona*,string>(angel->persona,"cielo"));
			}
		}
		angel=restantes.dequeue();
	}
	return lista;
}

Controller::Controller():QObject(),mundo(),infierno(),cielo(),cc(),ci(),cm(){
	makeConnections();
	cc.exec();
	ci.exec();
	cm.exec();
	cc.hide();
	ci.hide();
	cm.hide();
}

void Controller::abrirVentanaInfierno(){
	mw.hide();
	ci.show();
}

void Controller::abrirVentanaMundo(){
	mw.hide();
	cm.show();
}

void Controller::abrirVentanaParaiso(){
	mw.hide();
	cc.show();
}

void Controller::volverALaPrincipal(){
	cc.hide();
	ci.hide();
	cm.hide();
	mw.show();
}

bool comparaPersona::operator()(QPair<Persona*,string>const &e1, QPair<Persona*,string>const &e2){
	return pecados?e1.first->pecados[7]<e2.first->pecados[7]:e1.first->virtudes[7]<e2.first->virtudes[7];
}
