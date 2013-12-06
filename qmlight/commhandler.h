#ifndef COMMHANDLER_H
#define COMMHANDLER_H

#include <QObject>
#include <QString>
#include "qextserialport.h"

class CommHandler : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString error READ getError WRITE setError NOTIFY onError)


public:
	explicit CommHandler(QObject *parent = 0);
	virtual ~CommHandler(void);

	Q_INVOKABLE bool isOpen(void);
	QString getError(void);
	void setError(const QString);

signals:
	void onError(const QString &);

public slots:
	bool open(void);
	void close(void);



private:
	QextSerialPort *port;
	QString portId;
	bool statusOpen;
	QString error;

};

#endif // COMMHANDLER_H
