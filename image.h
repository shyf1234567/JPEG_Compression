#ifndef IMAGE_H
#define IMAGE_H
#include <QImage>
#include <QRgb>
#include <vector>
#include "global.h"
using namespace std;
class image
{
public:
    image(QImage *img);
    void Encode(int type);
    float get();
private:
    int blockX;
    int blockY;
    int width;
    int height;
    vector <vector<float> > colorY;//Y graph
    vector <vector<float> > colorU;//U graph
    vector <vector<float> > colorV;//V graph

    vector <vector<int> > Encode_Y;
    vector <vector<int> > Encode_U;
    vector <vector<int> > Encode_V;
};

#endif // IMAGE_H
