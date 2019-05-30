#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "infierno.h"
#include "mundo.h"
#include "paraiso.h"
#include <SMTPEmail/src/SmtpMime>
#include <QMessageBox>
#include <QString>

struct comparaPersona {
		bool pecados;
		comparaPersona(bool p):pecados(p){}
		bool operator()(QPair<Persona*,string>const&e1,QPair<Persona*,string>const&e2);
};

struct Controller
{
		Mundo mundo;
		Infierno infierno;
		Paraiso paraiso;
		void mandarAlInfierno(){
			enviarCorreo(infierno.condenar(mundo));
		}
		void salvarPersonas(){
			enviarCorreo(paraiso.salvarHumanos(infierno));
		}
		void enviarCorreo(string mensaje);
		QString qStringGanador(int i, int j){
			if (i<j)
				return "Cielo";
			else if (j<i)
				return "Infierno";
			else return "Empate!";
		}
		void ganador(){
			int**accionesInfierno=infierno.sumaAcciones();
			int**accionesParaiso=paraiso.sumaAcciones();
			for(int i=0;i<7;i++){
				QMessageBox(QMessageBox::Information,QString::fromStdString("Info ganador "+mundo.tiposPecados[i]+" vs "+mundo.tiposVirtudes[i]),
										"Cantidad pecado infierno: "+QString::number(accionesInfierno[0][i])+"\nCantidad virtud infierno: "+QString::number(accionesInfierno[1][i])+
						"\nNeto infierno: "+QString::number(accionesInfierno[0][i]-accionesInfierno[1][i])+
						"\nCantidad pecado cielo: "+QString::number(accionesParaiso[0][i])+"\nCantidad virtud cielo: "+QString::number(accionesParaiso[1][i])+
						"\nNeto cielo: "+QString::number(accionesParaiso[1][i]-accionesParaiso[0][i])+"\nGanador: "+qStringGanador(accionesInfierno[0][i]-accionesInfierno[1][i],accionesParaiso[1][i]-accionesParaiso[0][i]));
			}
		}
		QVector<QPair<Persona*,string>>getTodosLosDeLaFamilia(string apellido,string pais){
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
			NodoAngel*angel=paraiso.arbolDeAngeles.dios;
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
		void porcentajeFamiliaVivaVsCieloVsInfierno(string apellido,string pais){
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
		void todasLasPersonasApellidoPais(string apellido,string pais){
			QVector<QPair<Persona*,string>>porApellido=listadoPersonas(true,apellido,"apellido");
			QVector<QPair<Persona*,string>>porPais=listadoPersonas(true,pais,"pais");
			string text="";
			for(QPair<Persona*,string>p:porPais){
				if (porApellido.contains(p)){
					text+="Miembro localizado en: "+p.second+"\n"+p.first->to_string();
				}
			}
		}
		QVector<QPair<Persona*,string>> listadoPersonas(bool pecados,string filtro,string tipoFiltro){
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
			NodoAngel*angel=paraiso.arbolDeAngeles.dios;
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
		Controller();
};

#endif // CONTROLLER_H
