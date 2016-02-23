#include "display.h"
#include "ui_display.h"

display::display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);

}

void display::show_(QImage img)
{
    ui->label->setFixedSize(img.width(),img.height());
    ui->label->setPixmap(QPixmap::fromImage(img));
}

display::~display()
{
    delete ui;
}
