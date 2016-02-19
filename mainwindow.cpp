#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "image.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Browser_clicked()
{
    f = new FileBrowser();
    f->show();
}

void MainWindow::on_pushButton_clicked()
{
    img = new QImage(filePath);
    image *imgInfo = new image(img);
    qDebug()<< qRed(img->pixel(0,0))<<qGreen(img->pixel(0,0))<<qBlue(img->pixel(0,0));
    qDebug() << imgInfo->get();

}
