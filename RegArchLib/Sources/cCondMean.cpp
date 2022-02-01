#include "StdAfxRegArchLib.h"
/*!
 \file cAbstCondVar.cpp
 \brief sources for abstract class cAbstCondVar methods.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO 
 \date dec-18-2006 - Last change feb-18-2011
*/

namespace RegArchLib {
	/*!
	 * \fn cCondMean::cCondMean(uint theNCondMean)
	 * \param uint theNCondMean: number of conditional means
	 * \details mvCondMean = theNCondMean
	 */
	cCondMean::cCondMean(uint theNCondMean)
	{
		MESS_CREAT("cCondMean") ;
	}

	/*!
	 * \fn cCondMean::cCondMean(const cCondMean& theCondMean)
	 * \param cCondMean& theCondMean: conditional mean
	 * \details Recopy constructor
	 */
	cCondMean::cCondMean(const cCondMean& theCondMean)
	{
		MESS_CREAT("cCondMean") ;
	}

	/*!
	 * \fn cCondMean::~cCondMean()
	 * \param None
	 * \details simple destructor
	 */
	cCondMean::~cCondMean()
	{
		MESS_DESTR("cCondMean") ;
	}

	/*!
	 * \fn void cCondMean::Delete(void)
	 * \param void
	 * \details free memory used par the cCondMean class
	 */
	void cCondMean::Delete(void)
	{
		// complete
	}


}//namespace
