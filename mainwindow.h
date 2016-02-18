#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "filebrowser.h"
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

private:
    Ui::MainWindow *ui;
    FileBrowser *f;
    QImage *img;
};

#endif // MAINWINDOW_H
