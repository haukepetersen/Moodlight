#include "commhandler.h"

#include "QDebug"
#include "QIODevice"

CommHandler::CommHandler(QObject *parent) :
	QObject(parent)
{
	this->port = new QextSerialPort(QextSerialPort::EventDriven);
	error = QString("This is a fucking error");
}

CommHandler::~CommHandler(void)
{
	if (port->isOpen()) {
		port->close();
	}
	delete port;
}

bool CommHandler::open(void)
{
	if (!port->isOpen()) {
		port->setPortName(portId);
		return port->open(QIODevice::ReadWrite);
	}
	return false;
}

void CommHandler::close(void)
{
	port->close();
}


bool CommHandler::isOpen(void)
{
	return port->isOpen();
}

QString CommHandler::getError(void)
{
	return error;
}

void CommHandler::setError(const QString error)
{
	this->error = error;
	emit onError(this->error);
}
