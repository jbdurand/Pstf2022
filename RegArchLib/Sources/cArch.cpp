#include "StdAfxRegArchLib.h"

/*!
	\file cArch.cpp
	\brief sources for class cArch methods.

	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {
	/*!
	 * \fn cArch::cArch(uint theNArch):cAbstCondVar(eArch)
	 * \param uint theNArch: number of lags
	 */
	cArch::cArch(uint theNArch)
	:cAbstCondVar(eArch)   // call constructor of cAbstCondVar with type eArch
	{
		mvArch.ReAlloc(theNArch) ;
		MESS_CREAT("cArch")
	}

	/*!
	 * \fn cArch::~cArch()
	 */
	cArch::~cArch()
	{	mvArch.Delete() ;
  		MESS_DESTR("cArch") ;
	}

	/*!
	 * \fn void cArch::Delete(void)
	 * \param void
	 * \details Delete mvVar
	 */
	void cArch::Delete(void)
	{	mvArch.Delete() ;
	}

	/*!
	 * \fn void cArch::Print(ostream& theOut) const
	 * \param ostream& theOut: output stream (file or screen). Default cout.
	 */
	void cArch::Print(ostream& theOut) const
	{
	uint myNArch = mvArch.GetSize() ;
		theOut << "ARCH(" << myNArch << ") model with:" << endl ;
		theOut << "\tCste=" << mvConst << endl ;
		for (register uint i = 0 ; i < mvArch.GetSize() ; i++)
			theOut << "\tARCH[" << i+1 << "]=" << mvArch[i] << endl ;
	}

	void cArch::SetDefaultInitPoint(double theMean, double theVar)
	{
		mvConst = theVar*0.1 ;
	uint myNArch = mvArch.GetSize() ;
	uint i ;
		for (i = 0 ; i < myNArch ; i++)
			mvArch[i] = 0.9/(double)myNArch ;
	}

	/*!
	 * \fn void cArch::ReAlloc(uint theSize, uint theNumParam)
	 * \param uint theSize: new size of mvAr
	 * \param uint theNumParam: not used here.
	 * \details new allocation of mvArch
	 */
	void cArch::ReAlloc(uint theSize, uint theNumParam)
	{
		mvArch.ReAlloc(theSize) ;
	}

	/*!
	 * \fn void cArch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	 * \param const cDVector& theVectParam: the vector of Const or ARCH coefficients
	 * \param uint theNumParam: =0, the constant part; =1 the ARCH coefficients
	 * \details new allocation of mvArch or mvConst
	 */
	void cArch::ReAlloc(const cDVector& theVectParam, uint theNumParam)
	{	switch (theNumParam)
		{	case 0: // mvConst
				if (theVectParam.GetSize() > 0)
					mvConst = theVectParam[0] ;
				else
					throw cError("cArch::ReAlloc - Size of theVectParam must be > 0") ;
			break ;
			case 1 : // mvArch
				mvArch = theVectParam ;
			break ;
			default :
	//			throw cError("cArch::ReAlloc - theNumParam must be in 0, 1") ;
			break ;
		}
	}

	/*!
	 * \fn void cArch::Set(double theValue, uint theIndex, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param double theValue: the value of the "theIndex" th lag. Default 0.
	 * \param uint theIndex: the index.
	 * \param uint theNumParam: =0, mvConst, =1, ARCH parameters
	 * \details mvArch[theIndex] = theValue or mvConst = theValue
	 */
	void cArch::Set(double theValue, uint theIndex, uint theNumParam)
	{	switch (theNumParam)
		{	case 0 :
				mvConst = theValue ;
			break ;
			case 1 :
				if (theIndex < mvArch.GetSize())
					mvArch[theIndex] = theValue ;
				else
					throw cError("cArch::Set - wrong index") ;
			break ;
			default:
				throw cError("cArch::Set - theNumParam must be in 0, 1") ;
			break ;
		}
	}

	double  cArch::Get(uint theIndex, uint theNumParam)
	{
		switch (theNumParam)
		{	case 0 :
				return mvConst ;
			break ;
			case 1 :
				return mvArch[theIndex] ;
			break ;
		}
	}


	/*!
	 * \fn void cArch::Set(const cDVector& theVectParam, uint theNumParam)
	 * \brief fill the parameters vector
	 * \param const cDVector& theVectParam: the vector of values
	 * \param uint theNumParam: =0, mvConst; =1, mvArch
	 * \details mvArch = theVectParam or mvConst = theVectParam[0]
	 */
	void cArch::Set(const cDVector& theVectParam, uint theNumParam)
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
			default:
				throw cError("cArch::Set - theNumParam must be in 0, 1") ;
			break ;
		}
	}



	/*!
	 * \fn cAbstCondVar& cArch::operator =(cAbstCondVar& theSrc)
	 * \param cAbstCondVar& theSrc: source to be recopied
	 * \details An error occurs if theSrc is not an cArch class parameter
	 */
	cAbstCondVar& cArch::operator =(cAbstCondVar& theSrc)
	{
	cArch* myArch = dynamic_cast<cArch *>(&theSrc) ;
		if (myArch)
		{	
			copy(*myArch) ;
			mvConst = myArch->mvConst ;
		}
		else
			throw cError("wrong conditional variance class") ;
		return *this ;
	}

	uint cArch::GetNParam(void) const
	{
		// complete
	}

	void cArch::copy(const cArch& theArch)
	{
		mvConst = theArch.mvConst ;
		mvArch = theArch.mvArch;
	}
	

}//namespace
