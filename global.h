#ifndef GLOBAL
#define GLOBAL

#include "image.h"
#include <vector>
using namespace std;

class QString;
extern QString filePath;


vector <vector<float> > Product(vector< vector<float> > M1, vector< vector<float> > M2);
vector <vector<int> > DCT(vector <vector<int> > block);
vector <vector<int> > Quantization(vector <vector<int> > F, int type);
vector <vector<int> > IDCT(vector <vector<int> > block);
vector <vector<int> > IQuantizaiton(vector <vector<int> > F, int type);
void GetMatrix();
#endif // GLOBAL

