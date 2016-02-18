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
    int width;
    int height;
    vector < vector<int> > colorY;
    vector < vector<int> > colorU;
    vector < vector<int> > colorV;
};

#endif // IMAGE_H
