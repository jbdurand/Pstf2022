// Test.cpp : definit le point d'entree pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"

using namespace ErrorNameSpace;
using namespace VectorAndMatrixNameSpace;

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif //WIN32

#define cDVector cGSLVector 
#define cDMatrix cGSLMatrix  
{
    int i;
    double v;
    cDVector **myVectorCollection = new cDVector*[10];
    
    cout.precision(12) ; 

    // cDVector myMeans(10);

    
    for (i=0; i < 10; i++)  
    {
        myVectorCollection[i] = new cDVector(i+1, i*0.1);
    }

    for (i=0; i < 10; i++)  
    {
        v = (*myVectorCollection[0])[i];
    }
    
    for (i=0; i < 11; i++)  
    {
        delete myVectorCollection[i];
        // myVectorCollection[i] = NULL;
    }
    
    myVectorCollection[9]->Print(cout);
    
    delete [] myVectorCollection;
    myVectorCollection = NULL;
    
    return 0 ;


}
