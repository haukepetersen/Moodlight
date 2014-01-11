#ifndef CUTELIGHT_H
#define CUTELIGHT_H

#include <QMainWindow>

namespace Ui {
class Cutelight;
}

class Cutelight : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cutelight(QWidget *parent = 0);
    ~Cutelight();

private:
    Ui::Cutelight *ui;
};

#endif // CUTELIGHT_H
