#pragma once 
#ifndef _CGARCH_H_
#define _CGARCH_H_

#include "cAbstCondVar.h"
#include "cRegArchValue.h"
/*!
	\file cGarch.h
	\brief Definition of the GARCH(p, q) class
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {

	/*! 
	 * \class cGarch
	 * \brief Class to implement a 'pure' GARCH(p, q) model
	 */
	class _DLLEXPORT_ cGarch: public cAbstCondVar
	{
	private :
		double mvConst ; ///< Constant part of GARCH(p, q) variance model.
		cDVector mvArch ; ///< Vector of ARCH coefficients. 
		cDVector mvGarch ; ///< Vector of GARCH coefficients.
	public :
		cGarch(uint theNArch = 0, uint theNGarch=0) ; ///< A simple constructor
		cGarch(double theConst, cDVector& theArch, cDVector& theGarch) ; ///< Another constructor
		virtual ~cGarch() ; ///< A simple destructor
		void Delete(void) ; /// Delete
		void Print(ostream& theOut=cout) const ; ///< Print the parameters
		void SetDefaultInitPoint(double theMean, double theVar) ;
		void ReAlloc(uint theSize, uint theNumParam=0) ; ///< Allocation of the model parameters
		void ReAlloc(const cDVector& theVectParam, uint theNumParam=0) ; ///< Allocation of the model parameters
		void Set(double theValue, uint theIndex=0, uint theNumParam=0) ; ///< Set model parameters.
		void Set(const cDVector& theVectParam, uint theNumParam=0) ; ///< Set model parameters.
		double Get(uint theIndex=0, uint theNumParam=0) ;
		cAbstCondVar& operator=(cAbstCondVar& theSrc) ; ///< affectation operator for cGarch
		uint GetNParam(void) const ;
	private :
		void copy(const cGarch& theGarch) ; /// < Copy attribute from instance

	} ;

}
#endif // _CGARCH_H_
