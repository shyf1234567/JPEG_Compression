#include "global.h"
#include <QString>
#include <math.h>

#define PI 3.14159265
#define SQRT2 1.414213562
QString filePath = "";

vector <float> emptyFloat(8);
vector <int> emptyInt(8);

vector <vector<float> > Product(vector <vector<float> > M1, vector< vector<float> > M2)
{
    vector < vector<float> > result(8,emptyFloat);

    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            float tmp = 0;
            for (int k = 0; k < 8; k++)
                tmp += M1[i][k] * M2[k][j];
            result[i][j] = tmp;
        }
    }
    return result;
}

vector <vector<int> > DCT(vector <vector<float> > block)
{
    //construct 8*8 DCT matrix
    vector <vector <float> > DCTMatrix(8, emptyFloat);
    vector <vector <float> > DCTMatrixT(8, emptyFloat);
    vector <vector <float> > tmp;
    vector <vector <int> > result(8,emptyInt);

    for (int i = 0; i < 8; i++)
        DCTMatrix[0][i] = SQRT2;
    for (int i = 1; i < 8; i++)
        for (int j = 0; j < 8; j++)
            DCTMatrix[i][j] = (0.5 * cos((2 * j + 1) * i / 16.0 * PI / 180.0));

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            DCTMatrixT[i][j] = DCTMatrix[j][i];
    //DCT transfer
    tmp = Product(Product(DCTMatrix, block), DCTMatrixT);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            result[i][j] = (int)tmp[i][j];
    return result;
}

vector <vector<int> > Quantization(vector <vector<int> > F, int type)
{
    vector <vector<int> > LTable{{16, 11, 10, 16, 24, 40, 51, 61},
                                  {12, 12, 14, 19, 26, 58, 60, 55},
                                  {14, 13, 16, 24, 40, 57, 69, 56},
                                  {14, 17, 22, 29, 51, 87, 80, 62},
                                  {18, 22, 37, 56, 68, 109, 103, 77},
                                  {24, 35, 55, 64, 81, 104, 113, 92},
                                  {49, 64, 78, 87, 103, 121, 120, 101},
                                  {72, 92, 95, 98, 112, 100, 103, 99}};
    vector <vector<int> > CTable{{17, 18, 24, 47, 99, 99, 99, 99},
                                  {18, 21, 26, 66, 99, 99, 99, 99},
                                  {24, 26, 56, 99, 99, 99, 99, 99},
                                  {47, 66, 99, 99, 99, 99, 99, 99},
                                  {99, 99, 99, 99, 99, 99, 99, 99},
                                  {99, 99, 99, 99, 99, 99, 99, 99},
                                  {99, 99, 99, 99, 99, 99, 99, 99},
                                  {99, 99, 99, 99, 99, 99, 99, 99}};
    vector <vector<int> > result(8, emptyInt);
    if (type == 1)
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                result[i][j] = F[i][j] / LTable[i][j];
    }
    else
    {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                result[i][j] = F[i][j] / CTable[i][j];
    }
    return result;
}
