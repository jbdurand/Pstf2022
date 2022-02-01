#pragma once 
#ifndef _CCONDMEAN_H_
#define _CCONDMEAN_H_

#include "RegArchDef.h"
#include "cAbstCondMean.h"
#include "cRegArchValue.h"

/*!
	\file cCondMean.h
	\brief Definition of conditional mean class model
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/


namespace RegArchLib {
	/*! 
	 * \class cCondMean
	 * \brief Class definition of a conditional mean model
	 * \details A conditional mean model is always a sum of 'elementary' conditional mean components.
	 * \f$ m(t,\,\theta) = \sum_{i=1}^{NMean}{m_i(t,\,\theta)}\f$
	 */
	class _DLLEXPORT_ cCondMean
	{
	private :
		/// please complete this section
	public :
		cCondMean(uint theNCondMean = 0) ; ///< A simple constructor
		cCondMean(const cCondMean& theCondMean) ;
		virtual ~cCondMean() ; ///< A simple destructor
		void Delete(void) ; ///< Free memory.
		uint GetNMean(void) const ; ///< Return the number of mean components.
		// Complete
		// GetCondMean(void) const ; ///< Return mvCondMean
		void SetOneMean(uint theWhatMean, eCondMeanEnum theCode) ; ///< Set the type of a given mean component. 
		void SetOneMean(uint theWhatMean, cAbstCondMean& theAbstCondMean) ; ///< Set theWhatMean th component of the conditional mean model
		// Complete
		// GetOneMean(uint theIndex) const ; ///< Return a pointer to the given mean component  (no object is allocated)
		void Print(ostream& theOut=cout) const ; ///< Print the conditional mean model
		friend ostream& operator <<(ostream& theOut, const cCondMean& theCondMean) ; ///< Print the conditional mean model
		void SetDefaultInitPoint(double theMean, double theVar) ;
		void GetCondMeanType(eCondMeanEnum* theCodeType) const ; ///< Return the type of each mean component	
		cCondMean& operator =(cCondMean& theSrc) ; ///< affectation operator
		double ComputeMean(uint theDate, const cRegArchValue& theData) const ; ///< Return conditional mean.
		/** Number of parameters in CondMean */
		uint GetNParam(void) const ;
	} ;
}

#endif // _CCONDMEAN_H_

