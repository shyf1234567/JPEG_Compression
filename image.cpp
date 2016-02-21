#include "image.h"

image::image(QImage *img)
{
    width = img->width();
    height = img->height();
    for (int i = 0; i < height; i++)
    {
        vector <float> colY;
        vector <float> colU;
        vector <float> colV;
        for (int j = 0; j < width; j++)
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

void image::Encode(int type)
{
    int block_X = width / 8;
    int block_Y = height / 8;
    vector <int> Empty_Int(width * 8);
    vector <vector<int> > resultY(height * 8, Empty_Int);
    vector <vector<int> > resultU(height * 8, Empty_Int);
    vector <vector<int> > resultV(height * 8, Empty_Int);

    vector <float> emptyFloat(8);
    vector <int> emptyInt(8);
    vector <vector<float> > blockY(8, emptyFloat);
    vector <vector<float> > blockU(8, emptyFloat);
    vector <vector<float> > blockV(8, emptyFloat);

    vector <vector<int> > EncodeblockY(8, emptyInt);
    vector <vector<int> > EncodeblockU(8, emptyInt);
    vector <vector<int> > EncodeblockV(8, emptyInt);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int x = 0; x < 8; x++)
                for (int y = 0; y < 8; y++)
                {
                    blockY[x][y] = colorY[i * 8 + x][j * 8 + y];
                    blockU[x][y] = colorU[i * 8 + x][j * 8 + y];
                    blockV[x][y] = colorV[i * 8 + x][j * 8 + y];
                }
            EncodeblockY = Quantization(DCT(blockY), type);
            EncodeblockU = Quantization(DCT(blockU), type);
            EncodeblockV = Quantization(DCT(blockV), type);

            for (int x = 0; x < 8; x++)
                for (int y = 0; y < 8; y++)
                {
                    resultY[i * 8 + x][j * 8 + y] = EncodeblockY[x][y];
                    resultU[i * 8 + x][j * 8 + y] = EncodeblockU[x][y];
                    resultV[i * 8 + x][j * 8 + y] = EncodeblockV[x][y];
                }
        }
    }
    Encode_Y = resultY;
    Encode_U = resultU;
    Encode_V = resultV;

}
