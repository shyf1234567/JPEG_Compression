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
    float get();
private:
    int blockX;
    int blockY;
    int width;
    int height;
    vector < vector<float> > colorY;//Y graph
    vector < vector<float> > colorU;//U graph
    vector < vector<float> > colorV;//V graph
};

#endif // IMAGE_H
