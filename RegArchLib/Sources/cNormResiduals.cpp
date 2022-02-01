#include "StdAfxRegArchLib.h"

/*!
 \file cNormResiduals.cpp
 \brief implementation of the class for N(0, 1) conditional distribution.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*!
	 * \fn cNormResiduals::cNormResiduals(const cDVector* theDistrParameter, bool theSimulFlag):cAbstResiduals(eNormal, NULL, theSimulFlag)
	 * \param bool theSimulFlag: true if created for simulation
	 * \details: mvBool is initialised by cAbstResiduals constructor and theDistrParameter is never used.
	 */
	cNormResiduals::cNormResiduals(const cDVector* theDistrParameter, bool theSimulFlag):cAbstResiduals(eNormal, NULL, theSimulFlag)
	{
		MESS_CREAT("cNormResiduals")
	}

	/*!
	 * \fn cNormResiduals::~cNormResiduals
	 * \details: nothing to do here
	 */
	cNormResiduals::~cNormResiduals()
	{
		MESS_DESTR("cNormResiduals")
	}

	/*!
	 * \fn void cNormResiduals::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cNormResiduals::Print(ostream& theOut) const
	{
		theOut << "Conditional standardized normal distribution" << endl ;

	}
	/*!
	 * \fn double cNormResiduals::GetNParam(void)
	 * \param void.
	 */
	uint cNormResiduals::GetNParam(void) const
	{
		// complete
	}


}//namespace
