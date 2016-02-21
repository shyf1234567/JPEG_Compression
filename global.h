#ifndef GLOBAL
#define GLOBAL

#include "image.h"
#include <vector>
using namespace std;

class QString;
extern QString filePath;

vector <vector<float> > Product(vector< vector<float> > M1, vector< vector<float> > M2);
vector <vector<int> > DCT(vector <vector<float> > block);
vector <vector<int> > Quantization(vector <vector<int> > F, int type);
#endif // GLOBAL

