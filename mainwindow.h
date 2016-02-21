#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QMessageBox>
#include "filebrowser.h"
#include "image.h"
#include "global.h"
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

    void on_pushButton_clicked();

    void on_Encode1_clicked();

    void on_Show_clicked();

private:
    Ui::MainWindow *ui;
    FileBrowser *f;
    QImage *img;
    int Encode_type;
    image *imgInfo;
    QMessageBox box;
};

#endif // MAINWINDOW_H
