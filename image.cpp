#include "image.h"

image::image(QImage *img)
{
    width = img->width();
    height = img->height();
    for (int i = 0; i < width; i++)
    {
        vector <int> colY;
        vector <int> colU;
        vector <int> colV;
        for (int j = 0; j < height; j++)
        {
            QRgb color = img->pixel(i,j);
            int R = qRed(color);
            int G = qGreen(color);
            int B = qBlue(color);
            colY.push_back(int(0.299 * R + 0.587 * G + 0.114 * B));
            colU.push_back(int(-0.14713 * R - 0.28886 * G + 0.436 * B));
            colV.push_back(int(0.615 * R - 0.51499 * G - 0.10001 * B));
        }
        colorY.push_back(colY);
        colorU.push_back(colU);
        colorV.push_back(colV);
    }
}
int image::get()
{
    return colorY[0][0];
}

