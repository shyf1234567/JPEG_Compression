#ifndef IMAGE_H
#define IMAGE_H
#include <QImage>
#include <QRgb>
#include <vector>
using namespace std;
class image
{
public:
    image(QImage *img);
    int get();
private:
    int blockX;
    int blockY;
    int width;
    int height;
    vector < vector<int> > colorY;//Y graph
    vector < vector<int> > colorU;//U graph
    vector < vector<int> > colorV;//V graph
};

#endif // IMAGE_H
