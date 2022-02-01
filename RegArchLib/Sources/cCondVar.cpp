#include "StdAfxRegArchLib.h"
/*!
 \file cAbstCondVar.cpp
 \brief sources for abstract class cAbstCondVar methods.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO 
 \date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {
	/*!
	 * \fn cCondVar::cCondVar(uint theNCondVar)
	 * \param uint theNCondVar: number of conditional variances
	 * \details mvCondVar = theNCondVar
	 */
	cCondVar::cCondVar(uint theNCondVar)
	: mvCondVar()
	{	mvNCondVar = theNCondVar ;

		MESS_CREAT("cCondVar") ;
	}

	/*!
	 * \fn cCondVar::cCondVar(const cCondVar& theCondVar)
	 * \param cCondVar& theCondVar: conditional variance
	 * \details Recopy constructor
	 */
	cCondVar::cCondVar(const cCondVar& theCondVar)
	{
		// Complete
	}

	/*!
	 * \fn cCondVar::~cCondVar()
	 * \param None
	 * \details simple destructor
	 */
	cCondVar::~cCondVar()
	{	Delete() ;
		MESS_DESTR("cCondVar") ;
	}

	/*!
	 * \fn void cCondVar::Delete(void)
	 * \param void
	 * \details free memory used par the cCondVar class
	 */
	void cCondVar::Delete(void)
	{	
		// Complete
	}

	/*!
	 * \fn inline uint cCondVar::GetNVar(void) const
	 * \param void
	 * \brief return mvNCondVar
	 */
	uint cCondVar::GetNVar(void) const
	{
		return mvNCondVar ;
	}

	/*!
	 * \fn  void cCondVar::SetOneVar(uint theWhatVar, cAbstCondVar* theAbstCondVar)
	 * \param uint theWhatVar: index of the conditional variance component
	 * \param cAbstCondVar* theAbstCondVar: conditional variance component to be copied in the mCondVar array.
	 * \brief *mvCondVar[theWhatVar] = *theAbstCondVar
	 */
	void cCondVar::SetOneVar(uint theWhatVar, cAbstCondVar& theAbstCondVar)
	{
		// Complete
	}



	/*!
	 * \fn void cCondVar::GetCondVarType(eCondVarEnum* theCodeType) const
	 * \param eCondVarEnum* theCodeType: array of all conditional variance component codes
	 * \details fill theCodeType array
	 */
	void cCondVar::GetCondVarType(eCondVarEnum* theCodeType) const
	{	
	// Complete
	}

	/*!
	 * \fn void cCondVar::Print(ostream& theOut) const
	 * \param ostream& theOut: output stream (file or screen). Default cout.
	 */
	void cCondVar::Print(ostream& theOut) const
	{	
		// Complete
	}

	/*!
	 * \fn double cCondVar::Get(uint theNumVar, uint theIndex, uint theNumParam)
	 * \param uint theNumVar: index of
	 * \param ostream& theOut: output stream (file or screen). Default cout.
	 */
	double cCondVar::Get(uint theNumVar, uint theIndex, uint theNumParam)
	{
		return mvCondVar[theNumVar]->Get(theIndex, theNumParam) ;
	}
	
	/*!
	 * \fn ostream& operator <<(ostream& theOut, const cCondVar& theCondVar)
	 * \param ostream& theOut: output (file or screen).
	 * \param const cCondVar& theCondVar: the conditional variance class to be printed.
	 */
	ostream& operator <<(ostream& theOut, const cCondVar& theCondVar)
	{	
		// Complete
	}

	/*!
	 * \fn cCondVar& cCondVar::operator =(cCondVar& theSrc)
	 * \param cCondVar& theSrc: source class
	 */
	cCondVar& cCondVar::operator =(cCondVar& theSrc)
	{	
		// Complete
	}

	/*!
	 * \fn double cCondVar::ComputeVar(uint theDate, const cRegArchValue& theData) const
	 * \param int theDate: date of computation
	 * \param const cRegArchValue& theData: past datas.
	 * \details Compute the value of the conditional variance at date theDate.
	 * theData is not updated here.
	 */
	double cCondVar::ComputeVar(uint theDate, const cRegArchValue& theData) const
        {
		// Complete
	}
        
	uint cCondVar::GetNParam(void) const
	{
		// Complete
	}


}//namespace
