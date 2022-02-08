// Test.cpp : definit le point d'entree pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"
#include "StdAfxRegArchLib.h"

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
	 * ARMA / GARCH
	 *******/
        
        // cCondMean
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
<<<<<<< HEAD
	
        /*********
	 * A faire : etendre variance ARCH / GARCH
	 *******/
        
	cConstCondVar myConstVar(1.0) ;

	cCondVar myCondVar ;
	myCondVar.SetOneVar(0, myConstVar) ;
	
	cNormResiduals myNormResid ;

	cRegArchModel myModelArma ;
	myModelArma.SetMean(myCondMeanArma) ;
	myModelArma.SetVar(myCondVar) ;
	myModelArma.SetResid(myNormResid) ;
=======

        // cCondVar

        cCondVar myCondVarGarch ;
	cConstCondVar myConstVar(1.) ;
                
	cArch myArch(2) ;
	myArch.Set(0.1, 0) ;
	myArch.Set(0.2, 1) ;

        cGarch myGarch(1) ;
	myGarch.Set(0.4, 0) ;

        myCondVarGarch.SetOneVar(0, myConstVar);
        myCondVarGarch.SetOneVar(1, myArch);
        myCondVarGarch.SetOneVar(2, myGarch) ;

	cNormResiduals myNormResid ;

	cRegArchModel myModelArmaGarch ;
	myModelArmaGarch.SetMean(myCondMeanArma) ;
	myModelArmaGarch.SetResid(myNormResid) ;
	myModelArmaGarch.SetVar(myCondVarGarch) ;
>>>>>>> a2ee8b677bc6dca3eb14004cbfeeed8abd7450da
	cout << "Modele : " ;
	myModelArmaGarch.Print() ;
	
<<<<<<< HEAD
=======
	cRegArchModel myModelArmaCp(myModelArmaGarch) ;
	cout << "Copie du modele : " ;
	myModelArmaCp.Print() ;
>>>>>>> a2ee8b677bc6dca3eb14004cbfeeed8abd7450da

	// Simulation
	uint myNSample = 10;
	cRegArchValue mySimulData;
	cDVector mySimulVector(myNSample);
	RegArchLib::RegArchSimul(myNSample, myModelArma, mySimulData) ;
	cout << "Valeurs simulees : " << endl ;
	mySimulVector = mySimulData.mYt;
	mySimulVector.Print();


	/*********
	 * ARMA pur gaussien : gradient
	 *******/
	cout << "Modele : " ;
	myModelArma.Print() ;

	uint myNParam = myModelArma.GetNParam() ;
	cDVector myGrad0(myNParam) ;
	cDVector myGrad1(myNParam) ;

<<<<<<< HEAD
	// approximation par differences finies
	NumericRegArchGradLLH(myModelArma, mySimulData, myGrad0, 1e-6) ;
	cout << "Grad numerique" << endl << myGrad0 ;
	cRegArchGradient myGradData(&myModelArma) ;
	RegArchGradLLH(myModelArma, mySimulData, myGrad1) ;
	cout << "Grad calcule" << endl << myGrad1 ;
	cDVector myDiff = myGrad0 - myGrad1 ;
	for (register uint i = 0 ; i < myNParam ; i++)
        {
		if (myGrad0[i] != 0)
                {
                    myDiff[i] /= myGrad0[i] ;
                }
                else
                {
                    if (myGrad0[i] == 0)
                        myDiff[i] = 0.0;
                    else
                        myDiff[i] = nanf("");
                }
        }
	cout << "erreur relative (%)" << endl << 100*myDiff ;
=======
	// Moyennes conditionnelles
	uint myNData = 25 ;
	cRegArchValue myGivenValue(myNData) ;
	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
		myGivenValue.mYt[t] = t;
	}

	cDVector myMeans(myNData);	
        // Moyennes conditionnelles

	for(uint t=0; t < myGivenValue.mYt.GetSize(); t++)
	{
		myMeans[t] = myModelArmaGarch.ComputeMean(t, myGivenValue);
		myGivenValue.mUt[t] = myGivenValue.mYt[t] - myMeans[t];
		myGivenValue.mMt[t] = myMeans[t];
	}
	cout << "Moyennes conditionnelles ARMA pur gaussien : " << endl ;
	myMeans.Print();
>>>>>>> a2ee8b677bc6dca3eb14004cbfeeed8abd7450da

	// Simulation
	uint myNSample = 10;
	cRegArchValue mySimulData;
	cDVector mySimulVector(myNSample);
	RegArchLib::RegArchSimul() ;
	cout << "Valeurs simulees : " << endl ;
	mySimulVector = mySimulData.mYt;
	mySimulVector.Print();
        
        // Calcul de vraisemblance
        double myLoglikelihood = 0.;
        myLoglikelihood = RegArchLLH(myModelArmaGarch, myGivenValue);
        cout << "Log-vraisemblance : " << myLoglikelihood << endl;

	return 0 ;


}
