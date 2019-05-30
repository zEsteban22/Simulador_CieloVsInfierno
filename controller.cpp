#include "controller.h"

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

Controller::Controller()
{

}

bool comparaPersona::operator()(QPair<Persona*,string>const &e1, QPair<Persona*,string>const &e2){
	return pecados?e1.first->pecados[7]<e2.first->pecados[7]:e1.first->virtudes[7]<e2.first->virtudes[7];
}
