#include "image.h"
image::image(QImage *img)
{
    width = img->width();
    height = img->height();
    block_X = width / 8;
    block_Y = height / 8;
    vector <int> Empty_Int(width);
    vector <vector<int> > resultY(height, Empty_Int);
    vector <vector<int> > resultU(height, Empty_Int);
    vector <vector<int> > resultV(height, Empty_Int);

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            QRgb color = img->pixel(j,i);
            resultY[i][j] = 0.299 * qRed(color) + 0.587 * qGreen(color) + 0.114 * qBlue(color);
            resultU[i][j] = -0.14713 * qRed(color) - 0.28886 * qGreen(color) + 0.436 * qBlue(color);
            resultV[i][j] = 0.615 * qRed(color) - 0.51499 * qGreen(color) - 0.10001 * qBlue(color);
         }
    colorY = resultY;
    colorU = resultU;
    colorV = resultV;
}
void image::Decode(int type)
{
    vector <int> Empty_Int(block_X * 8);
    vector <vector<int> > resultY(block_Y * 8, Empty_Int);
    vector <vector<int> > resultU(block_Y * 8, Empty_Int);
    vector <vector<int> > resultV(block_Y * 8, Empty_Int);
    vector <vector<int> > resultR(block_Y * 8, Empty_Int);
    vector <vector<int> > resultG(block_Y * 8, Empty_Int);
    vector <vector<int> > resultB(block_Y * 8, Empty_Int);

    vector <int> emptyInt(8);
    vector <vector<int> > blockY(8, emptyInt);
    vector <vector<int> > blockU(8, emptyInt);
    vector <vector<int> > blockV(8, emptyInt);

    vector <vector<int> > EncodeblockY(8, emptyInt);
    vector <vector<int> > EncodeblockU(8, emptyInt);
    vector <vector<int> > EncodeblockV(8, emptyInt);

    GetMatrix();

    for (int i = 0; i < block_Y; i++)
    {
        for (int j = 0; j < block_X; j++)
        {
            for (int x = 0; x < 8; x++)
                for (int y = 0; y < 8; y++)
                {
                    blockY[x][y] = Encode_Y[i * 8 + x][j * 8 + y];
                    blockU[x][y] = Encode_U[i * 8 + x][j * 8 + y];
                    blockV[x][y] = Encode_V[i * 8 + x][j * 8 + y];
                }
            EncodeblockY = IDCT(IQuantizaiton(blockY, type));
            EncodeblockU = IDCT(IQuantizaiton(blockU, type));
            EncodeblockV = IDCT(IQuantizaiton(blockV, type));
            for (int x = 0; x < 8; x++)
                for (int y = 0; y < 8; y++)
                {
                    resultY[i * 8 + x][j * 8 + y] = EncodeblockY[x][y];
                    resultU[i * 8 + x][j * 8 + y] = EncodeblockU[x][y];
                    resultV[i * 8 + x][j * 8 + y] = EncodeblockV[x][y];
                }
        }
    }
    for (int i = 0; i < block_Y * 8; i++)
        for (int j = 0; j < block_X * 8; j++)
        {
            resultR[i][j] = resultY[i][j] + resultV[i][j] * 1.13983;
            resultG[i][j] = resultY[i][j] - resultU[i][j] * 0.39465 - resultV[i][j] * 0.58060;
            resultB[i][j] = resultY[i][j] + resultU[i][j] * 2.03211;
        }
    Decode_R = resultR;
    Decode_G = resultG;
    Decode_B = resultB;

}

void image::Encode(int type)
{
    vector <int> Empty_Int(block_X * 8);
    vector <vector<int> > resultY(block_Y * 8, Empty_Int);
    vector <vector<int> > resultU(block_Y * 8, Empty_Int);
    vector <vector<int> > resultV(block_Y * 8, Empty_Int);

    vector <int> emptyInt(8);
    vector <vector<int> > blockY(8, emptyInt);
    vector <vector<int> > blockU(8, emptyInt);
    vector <vector<int> > blockV(8, emptyInt);

    vector <vector<int> > EncodeblockY(8, emptyInt);
    vector <vector<int> > EncodeblockU(8, emptyInt);
    vector <vector<int> > EncodeblockV(8, emptyInt);

    GetMatrix();
    for (int i = 0; i < block_Y; i++)
    {
        for (int j = 0; j < block_X; j++)
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

QImage image::Generate()
{
    QImage pic(block_X * 8, block_Y * 8,QImage::Format_RGB32);
    pic.fill(QColor(Qt::white).rgb());
    for (int i = 0; i < block_Y * 8; i++)
        for (int j = 0; j < block_X * 8; j++)
        {
            if (Decode_R[i][j] < 0)
                Decode_R[i][j] = 0;
            if (Decode_R[i][j] > 255)
                Decode_R[i][j] = 255;
            if (Decode_G[i][j] < 0)
                Decode_G[i][j] = 0;
            if (Decode_G[i][j] > 255)
                Decode_G[i][j] = 255;
            if (Decode_B[i][j] < 0)
                Decode_B[i][j] = 0;
            if (Decode_B[i][j] > 255)
                Decode_B[i][j] = 255;
            //qDebug()<<Decode_R[i][j] <<Decode_G[i][j] <<Decode_B[i][j];
            pic.setPixel(j,i,qRgb(Decode_R[i][j], Decode_G[i][j], Decode_B[i][j]));
        }
    return pic;
}
