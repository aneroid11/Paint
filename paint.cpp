#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Paint)
{
    ui->setupUi(this);
}

Paint::~Paint()
{
    delete ui;
}

