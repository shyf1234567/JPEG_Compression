#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>
#include <QImage>
namespace Ui {
class display;
}

class display : public QDialog
{
    Q_OBJECT

public:
    void show_(QImage img);
    explicit display(QWidget *parent = 0);
    ~display();

private:
    Ui::display *ui;
};

#endif // DISPLAY_H
