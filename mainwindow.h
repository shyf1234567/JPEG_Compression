#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QMessageBox>
#include "filebrowser.h"
#include "image.h"
#include "global.h"
#include "display.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Browser_clicked();

    void on_Show_clicked();

    void on_Encode1_clicked();

    void on_Encode2_clicked();

    void on_Decode_clicked();

    void on_Next_clicked();

private:
    Ui::MainWindow *ui;
    FileBrowser *f;
    QImage *img;
    int Encode_type;
    int pic_num;
    image *imgInfo;
    QMessageBox box;
    display *pic;
};

#endif // MAINWINDOW_H
