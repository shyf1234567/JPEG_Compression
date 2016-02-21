#ifndef IMAGE_H
#define IMAGE_H
#include <QImage>
#include <QRgb>
#include <QDebug>
#include <vector>
#include "global.h"
using namespace std;
class image
{
public:
    image(QImage *img);
    void Encode(int type);
    void Decode(int type);
    void Generate();
    void get();
private:
    int width;
    int height;
    int block_X;
    int block_Y;
    vector <vector<int> > colorY;//Y graph
    vector <vector<int> > colorU;//U graph
    vector <vector<int> > colorV;//V graph

    vector <vector<int> > Encode_Y;// encoding Y graph
    vector <vector<int> > Encode_U;// encoding U graph
    vector <vector<int> > Encode_V;// encoding V graph

    vector <vector<int> > Decode_R;
    vector <vector<int> > Decode_G;
    vector <vector<int> > Decode_B;


};

#endif // IMAGE_H
