#ifndef COLORMODEL_H
#define COLORMODEL_H

#include <QObject>
#include <QColor>

class ColorModel : public QObject
{
	Q_OBJECT
public:
	explicit ColorModel(QObject *parent = 0);
	
signals:
	
public slots:
	void setColor(QColor &color);

private:
	QColor currentColor;
};

#endif // COLORMODEL_H
