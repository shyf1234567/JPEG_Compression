#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "image.h"
#include <QDebug>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Encode_type =0;
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


void MainWindow::on_Show_clicked()
{
    img = new QImage(filePath);
    imgInfo = new image(img);
    QPixmap mypix(filePath);
    ui->label->setPixmap(mypix);
}

void MainWindow::on_Encode1_clicked()
{
    Encode_type = 1;
    imgInfo->Encode(1);
    box.setText("Encode successfully!");
    box.exec();
}

void MainWindow::on_Encode2_clicked()
{
    Encode_type = 2;
    imgInfo->Encode(2);
    box.setText("Encode successfully!");
    box.exec();
}

void MainWindow::on_Decode_clicked()
{
    if (Encode_type == 0)
    {
        box.setText("Nothing to Decode");
        box.exec();
    }
    else
    {
        imgInfo->Decode(Encode_type);
        ui->label->setPixmap(QPixmap::fromImage(imgInfo->Generate()));
        box.setText("Decode successfully!");
        box.exec();
        Encode_type = 0;
    }
}
