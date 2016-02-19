#include "image.h"

image::image(QImage *img)
{
    width = img->width();
    height = img->height();
    for (int i = 0; i < width; i++)
    {
        vector <float> colY;
        vector <float> colU;
        vector <float> colV;
        for (int j = 0; j < height; j++)
        {
            QRgb color = img->pixel(i,j);
            int R = qRed(color);
            int G = qGreen(color);
            int B = qBlue(color);
            //4:2:0 chroma subsampling
            colY.push_back(int(0.299 * R + 0.587 * G + 0.114 * B));
            if (j % 2)//only Y
            {
                colU.push_back(0);
                colV.push_back(0);
            }
            else if (i % 2)//Y and U
            {
                colU.push_back(int(-0.14713 * R - 0.28886 * G + 0.436 * B));
                colV.push_back(0);
            }
            else//Y and V
            {
                colU.push_back(0);
                colV.push_back(int(0.615 * R - 0.51499 * G - 0.10001 * B));
            }
        }
        colorY.push_back(colY);
        colorU.push_back(colU);
        colorV.push_back(colV);
    }
}
float image::get()
{
    return colorY[0][0];
}

