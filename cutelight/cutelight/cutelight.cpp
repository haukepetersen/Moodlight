#include "cutelight.h"
#include "ui_cutelight.h"

Cutelight::Cutelight(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cutelight)
{
    ui->setupUi(this);
}

Cutelight::~Cutelight()
{
    delete ui;
}
