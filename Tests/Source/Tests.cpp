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
	
	cConstCondVar myConstVar(1.0) ;
	
	cNormResiduals myNormResid ;

	cRegArchModel myModelArma ;
	myModelArma.SetMean(myCondMeanArma) ;
	myModelArma.SetResid(myNormResid) ;
	myModelArma.SetVar(myConstVar) ;
	cout << "Modele : " ;
	myModelArma.Print() ;
	
	cRegArchModel myModelArmaCp(myModelArma) ;
	cout << "Copie du modele : " ;
	myModelArmaCp.Print() ;


	return 0 ;


}
