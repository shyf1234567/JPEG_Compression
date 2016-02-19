#include "global.h"
#include <QString>
#include <math.h>

#define PI 3.14159265
#define SQRT2 1.414213562
QString filePath = "";

vector < vector<float> > Product(vector< vector<float> > M1, vector< vector<float> > M2)
{
    vector <float> empty(8);
    vector < vector<float> > result(8,empty);

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

vector <vector <int> > DCT(vector< vector<float> > block)
{
    //construct 8*8 DCT matrix
    vector <float> emptyFloat(8);
    vector <int> emptyInt(8);
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
