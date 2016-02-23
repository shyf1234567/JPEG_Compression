#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "global.h"
#include "image.h"
#include <QDebug>
#include <QPixmap>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    pic = new display();
    Encode_type =0;
    pic_num = 0;
    ui->setupUi(this);
    ui->text->setFont(QFont("Courier",20));
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
    ui->label->setFixedSize(img->width(), img->height());
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
        //ui->label->setPixmap(QPixmap::fromImage(imgInfo->Generate()));
        box.setText("Decode successfully!");
        box.exec();
        pic->show_(imgInfo->Generate());
        pic->show();
        Encode_type = 0;
    }
}

void MainWindow::on_Next_clicked()
{
    pic_num++;
    if (pic_num > 6)
        pic_num -= 6;
    if (pic_num < 4)
    {
        ui->label->setPixmap(QPixmap::fromImage((imgInfo->GenerateOriginalYUV(pic_num))));
        switch (pic_num)
        {
        case 1: ui->text->setText("Original Y image");break;
        case 2: ui->text->setText("Original U image");break;
        case 3: ui->text->setText("Original V image");break;
        }
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage((imgInfo->GenerateEncodeYUV(pic_num))));
        ui->text->setFixedWidth(1000);
        switch (pic_num)
        {
        case 4: ui->text->setText("Y image after Encoding");break;
        case 5: ui->text->setText("U image after Encoding");break;
        case 6: ui->text->setText("V image after Encoding");break;
        }
    }
}
