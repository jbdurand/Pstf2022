#include "StdAfxRegArchLib.h"
/*!
	\file cGarch.cpp
	\brief sources for class cGarch methods.

	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cGarch::cGarch(uint theNArch, uint theNGarch):cAbstCondVar(eGarch)
	 * \param uint theNArch: number of ARCH lags
	 * \param uint theNGarch: number of GARCH lags
	*/
	cGarch::cGarch(uint theNArch, uint theNGarch)
	:cAbstCondVar(eGarch)  // call constructor of cAbstCondVar with type eGarch
	{	
		mvArch.ReAlloc(theNArch) ;
		mvGarch.ReAlloc(theNGarch) ;
		mvConst = 0.0 ;
		MESS_CREAT("cGarch") ;
	}

	/*!
	 * \fn cGarch::cGarch(double theConst, cDVector& theArch, cDVector& theGarch):cAbstCondVar(eGarch)
	 * \param double theConst: constant part of the GARCH(p, q) model
	 * \param cDVector& theGarch theArch: ARCH parameters
	 * \param cDVector& theGarch theGarch: GARCH parameters
	*/
	cGarch::cGarch(double theConst, cDVector& theArch, cDVector& theGarch):cAbstCondVar(eGarch)
	{	mvConst = theConst ;
		mvArch = theArch ;
		mvGarch = theGarch ;
		MESS_CREAT("cGarch") ;
	}
	/*!
	 * \fn cGarch::~cGarch()
	*/
	cGarch::~cGarch()
	{	mvArch.Delete() ;
		mvGarch.Delete() ;
		MESS_DESTR("cGarch") ;
	}

	/*!
	 * \fn void cGarch::Delete(void)
	 * \param void
	 * \details Free memory
	 */
	void cGarch::Delete(void)
	{	mvArch.Delete() ;
		mvGarch.Delete() ;
	}
	/*!
	 * \fn void cGarch::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cGarch::Print(ostream& theOut) const
	{
	uint myNArch = mvArch.GetSize() ;
	uint myNGarch = mvGarch.GetSize() ;
		theOut << "GARCH(" << myNArch <<", " << myNGarch << ") model with:" << endl ;
		theOut << "\tCste=" << mvConst << endl ;
		for (register uint i = 0 ; i < myNArch ; i++)
			theOut << "\tARCH[" << i+1 << "]=" << mvArch[i] << endl ;
		for (register uint j = 0 ; j < myNGarch ; j++)
			theOut << "\tGARCH[" << j+1 << "]=" << mvGarch[j] << endl ;
	}


	/*!
	 * \fn void cGarch::ReAlloc(uint theSize, uint theNumParam)
	 * \param uint theSize: new size of mvArch or mvGarch
	 * \param uint theNumParam: 0 for mvArch, 1 for mvGarch.
	 * \details new allocation of mvArch or mvGarch
	 */
	void cGarch::ReAlloc(uint theSize, uint theNumParam)
	{
		switch (theNumParam)
		{	case 1 :
				mvArch.ReAlloc(theSize) ;
			break ;
			case 2 :
				mvGarch.ReAlloc(theSize) ;
			break ;
			default :
	//			throw cError("cGarch::ReAlloc - theNumParam must be in 1, 2.") ;
			break ;
		}
	}

	/*!
	 * \fn void cGarch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of Const, ARCH or GARCH coefficients
	 * \param uint theNumParam: =0, the constant part; =1 the ARCH coefficients; =2 theGARCH Coefficients
	 * \details new allocation of mvArch or mvConst
	 */
	void cGarch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	{	switch (theNumParam)
		{	case 0: // mvConst
				if (theVectParam.GetSize() > 0)
					mvConst = theVectParam[0] ;
				else
					throw cError("cGarch::ReAlloc - Size of theVectParam must be > 0") ;
			break ;
			case 1 : // mvArch
				mvArch = theVectParam ;
			break ;
			case 2 : // mvGarch
				mvGarch = theVectParam ;
			break ;
			default :
				throw cError("cGarch::ReAlloc - theNumParam must be in 0, 1, 2") ;
			break ;
		}
	}

	/*!
	 * \fn void cGarch::Set(double theValue, uint theIndex, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param double theValue: the value of the "theIndex" th lag. Default 0.
	 * \param uint theIndex: the index.
	 * \param uint theNumParam: =0, mvConst, =1, ARCH parameters; =2, GARCH parameters
	 * \details mvArch[theIndex] = theValue or mvGarch[theIndex]= theValue or mvConst = theValue
	 */
	void cGarch::Set(double theValue, uint theIndex, uint theNumParam)
	{	switch (theNumParam)
		{	case 0 :
				mvConst = theValue ;
			break ;
			case 1 :
				if (theIndex < mvArch.GetSize())
					mvArch[theIndex] = theValue ;
				else
					throw cError("cGarch::Set - wrong index") ;
			break ;
			case 2 :
				if (theIndex < mvGarch.GetSize())
					mvGarch[theIndex] = theValue ;
				else
					throw cError("cGarch::Set - wrong index") ;
			break ;
			default:
				throw cError("cGarch::Set - theNumParam must be in 0, 1, 2") ;
			break ;
		}
	}

	/*!
	 * \fn void cGarch::Set(const cDVector& theVectParam, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the vector of values
	 * \param uint theNumParam: =0, mvConst, =1, ARCH parameters; =2, GARCH parameters
	 * \details mvAr = theValue
	 */
	void cGarch::Set(const cDVector& theVectParam, uint theNumParam)
	{	switch (theNumParam)
		{	case 0 :
				if (theVectParam.GetSize() > 0)
					mvConst = theVectParam[0] ;
				else
					throw cError("cArch::Set - Size of theVectParam must be > 0") ;
			break ;
			case 1 :
				mvArch = theVectParam ;
			break ;
			case 2 :
				mvGarch = theVectParam ;
			break ;
			default:
				throw cError("cArch::Set - theNumParam must be in 0, 1, 2") ;
			break ;
		}
	}

	double  cGarch::Get(uint theIndex, uint theNumParam)
	{
		switch (theNumParam)
		{	case 0 :
				return mvConst ;
			break ;
			case 1 :
				return mvArch[theIndex] ;
			break ;
			case 2 :
				return mvGarch[theIndex] ;
			break ;
		}
	}

	/*!
	 * \fn cAbstCondVar& cGarch::operator =(cAbstCondVar& theSrc)
	 * \param cAbstCondVar& theSrc: source to be recopied
	 * \details An error occurs if theSrc is not an cGarch class parameter
	 */
	cAbstCondVar& cGarch::operator =(cAbstCondVar& theSrc)
	{
	cGarch* myGarch = dynamic_cast<cGarch *>(&theSrc) ;
		if (myGarch)
		{	
			copy(*myGarch) ;
		}
		else
			throw cError("wrong conditional variance class") ;
		return *this ;
	}

	uint cGarch::GetNParam(void) const
	{
		// complete
	}

	void cGarch::copy(const cGarch& theGarch)
	{
		mvConst = theGarch.mvConst;
		mvArch = theGarch.mvArch;
		mvGarch = theGarch.mvGarch;
	}
	

}//namespace
