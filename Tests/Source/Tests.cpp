// Test.cpp : definit le point d'entree pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"

using namespace ErrorNameSpace;
using namespace VectorAndMatrixNameSpace;
using namespace RegArchLib ;

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif //WIN32
{
	cout.precision(12) ; 

	/*********
	 * ARMA pur
	 *******/
	cConst myConst(0.1);
	
	cAr	myAr(2) ;
	
	myAr.Set(.8, 0) ;
	myAr.Set(-.2, 1) ;
	myAr.Print() ;
	
	cMa myMa(2) ;
	myMa.Set(0.8, 0) ;
	myMa.Set(0.6, 1) ;
	
	cCondMean myCondMeanArma ;
	myCondMeanArma.SetOneMean(0, myConst) ;
	myCondMeanArma.SetOneMean(1, myAr) ;
	myCondMeanArma.SetOneMean(2, myMa) ;

	const double myConstVar = 1. ;
        cConstCondVar myConstCondVar(myConstVar);

	cDVector myArch(2) ;
	myArch[0] = 0.1 ;
	myArch[1] = 0.2 ;
        
        cArch mycArch(2);
        mycArch.Set(myArch);

        cDVector myGarch(1) ;
	myGarch[0] = 0.4 ;
        
        cGarch mycGarch(1);
        mycGarch.Set(myGarch);
        
	cCondVar myCondVar ;
	myCondVar.SetOneVar(0, myConstCondVar) ;
        myCondVar.SetOneVar(1, mycArch) ;
        myCondVar.SetOneVar(1, mycGarch) ;
        
	cNormResiduals myNormResid ;

	cRegArchModel myModelArma ;
	myModelArma.SetMean(myCondMeanArma) ;
	myModelArma.SetResid(myNormResid) ;
	myModelArma.SetVar(myCondVar) ;
	cout << "Modele : " ;
	myModelArma.Print() ;
	

	// Simulation
	uint myNSample = 10;
	cRegArchValue mySimulData;
	cDVector mySimulVector(myNSample);
	RegArchLib::RegArchSimul(myNSample, myModelArma, mySimulData) ;
	cout << "Valeurs simulees : " << endl ;
	mySimulVector = mySimulData.mYt;
	mySimulVector.Print();


	/*********
	 * ARMA / GARCH Student : gradient
	 *******/
	cout << "Modele : " ;
	myModelArma.Print() ;

	uint myNParam = myModelArma.GetNParam() ;
	cDVector myGrad0(myNParam) ;
	cDVector myGrad1(myNParam) ;

	// approximation par differences finies
	NumericRegArchGradLLH(myModelArma, mySimulData, myGrad0, 1e-6) ;
	cout << "Grad numerique" << endl << myGrad0 ;
	cRegArchGradient myGradData(&myModelArma) ;
	RegArchGradLLH(myModelArma, mySimulData, myGrad1) ;
	cout << "Grad calcule" << endl << myGrad1 ;
	cDVector myDiff = myGrad0 - myGrad1 ;
	for (register uint i = 0 ; i < myNParam ; i++)
		myDiff[i] /= myGrad0[i] ;
	cout << "erreur relative (%)" << endl << 100*myDiff ;


	return 0 ;


}
