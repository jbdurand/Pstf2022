#pragma once 
#ifndef _CREGARCHMODEL_
#define _CREGARCHMODEL_

#include "cCondMean.h"
#include "cAbstCondVar.h"
#include "cAbstResiduals.h"

/*!
 \file cRegArchModel.h
 \brief header for class cRegArchModel.

 \author Jean-Baptiste DURAND, Ollivier TARAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {
	/*! 
	 * \class cRegArchModel
	 * \brief  Class to implement a general RegArch model
	 */
	class _DLLEXPORT_ cRegArchModel
	{
	public :
        // complete
			mMean	; ///< conditional mean model
			mVar	; ///< conditional variance model
			mResids	; ///< conditional residuals distribution model
	public :
		cRegArchModel();
		// Complete
        // cRegArchModel( theMean, theVar, theResiduals) ; ///< A simple constructor
		cRegArchModel(cRegArchModel& theModel) ; ///< Recopy constructor
		virtual ~cRegArchModel() ; ///< Destructor
		cRegArchModel& operator=(cRegArchModel& theRegArchModel) ; ///< = operator for cRegArchModel Class		int GetNMean(void) ;
		void ReAllocMean(uint theNewSize) ; ///< Change the number of components for conditional mean
		void SetMean(cCondMean& theCondMean) ; ///< Change all components for conditional mean
		void AddOneMean(cAbstCondMean& theOneMean) ; ///< Add one component for conditional mean
		// Complete
		//  GetOneMean(int theNumMean) ;
		bool IsGoodMeanType(eCondMeanEnum theMeanEnum, int theIndex) ;
		// Complete 
		// void SetVar( theCondVar) ; ///< Add (unique) component for conditional mean
		// Complete
		// GetVar(void) ;
		// Complete void SetResid(theCondResids) ; ///< Add (unique) distribution for the distribution of residuals
		// Complete
		// GetResid(void) ; ///< Add (unique) distribution for the distribution of residuals
		void PrintMean(ostream& theOut=cout) const; ///< Print conditional mean model
		void PrintVar(ostream& theOut=cout) const;  ///< Print conditional var model
		void PrintResiduals(ostream& theOut=cout) const; ///< Print conditional residuals distribution model
		void Print(ostream& theOut=cout) const; ///< Print the whole model
		uint GetNParam(void) const ; ///< Return the number of model parameters
	} ;
}
#endif // _CREGARCHMODEL_
