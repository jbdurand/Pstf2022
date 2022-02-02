#include "StdAfxRegArchLib.h"
/*!
 \file cRegArchModel.cpp
 \brief sources for class cRegArchModel methods.

 \author Jean-Baptiste Durand, Ollivier TMAAMASCO
 \date dec-18-2006 - Last change feb-18-2011
*/
namespace RegArchLib {

	/*!
	 * \fn cRegArchModel::cRegArchModel()
	 * \param None
	 * \details A simple constructor
	 */
	cRegArchModel::cRegArchModel()
	{
		mMean = NULL ;
		mVar = NULL ;
		mResids = NULL ;
	}

	cRegArchModel::cRegArchModel(theMean, theVar, theResiduals)
	{	
		// complete
		
 		MESS_CREAT("cRegArchModel") ;
	}

	/*!
	 * \fn cRegArchModel::cRegArchModel(cRegArchModel& theModel)
	 * \param cRegArchModel& theModel: the source
	 * \details recopy constructor
	 */
		cRegArchModel::cRegArchModel(cRegArchModel& theModel)
		{	
			// complete

 			MESS_CREAT("cRegArchModel") ;
		}

	/*!
	 * \fn cRegArchModel::~cRegArchModel()
	 */
	cRegArchModel::~cRegArchModel()
	{	if (mMean != NULL)
		{	mMean->Delete() ;
			delete mMean ;
		}
		if (mVar != NULL)
		{	mVar->Delete() ;
			delete mVar ;
		}
		if (mResids != NULL)
		{	mResids->Delete() ;
			delete mResids ;
		}
		MESS_DESTR("cRegArchModel") ;
	}

	/*!
	 * \fn void cRegArchModel::GetNMean(void)
	 * \param void
	 * \details return the number of mean components
	 */
	int cRegArchModel::GetNMean(void)
	{
		if (mMean == NULL)
			return 0 ;
		else
			return mMean->GetNMean() ;
	}

	void cRegArchModel::ReAllocMean(uint theNewSize)
	{
		if (mMean != NULL)
		{
			mMean->Delete() ;
			delete mMean ;
		}
		mMean = new cCondMean(theNewSize) ;
	}

	/*!
	 * \fn void cRegArchModel::SetMean(cCondMean& theCondMean)
	 * \param cCondMean& theCondMean: the conditional mean model
	 */
	void cRegArchModel::SetMean(cCondMean& theCondMean)
	{
		if (mMean != NULL)
		{
			mMean->Delete() ;
			delete mMean ;
		}

		mMean = new cCondMean(theCondMean) ;
	}

	/*!
	 * \fn void cRegArchModel::GetNMean(void)
	 * \param void
	 * \details return the number of mean components
	 */
	int cRegArchModel::GetNMean(void)
	{
		if (mMean == NULL)
			return 0 ;
		else
			return mMean->GetNMean() ;
	}

	/*!
	 * \fn void cRegArchModel::AddOneMean(cAbstCondMean& theOneMean)
	 * \param cAbstCondMean& theOneMean: the conditional mean component model
	 * \details Add a new mean component
	 */
	void cRegArchModel::AddOneMean(cAbstCondMean& theOneMean)
	{
	int myWhere ;
		if (mMean == NULL)
		{	myWhere = 0 ;
			mMean = new cCondMean(1) ;
		}
		else
			myWhere = (int)mMean->GetNMean() ;
		mMean->SetOneMean(myWhere, theOneMean) ;
	}
	
	cRegArchModel::GetOneMean(int theNumMean)
	{	
		// complete
	}

	bool cRegArchModel::IsGoodMeanType(eCondMeanEnum theMeanEnum, int theIndex)
	{
		if (mMean != NULL)
		{	cAbstCondMean* myCondMean = mMean->GetOneMean(theIndex) ;
			return (myCondMean->GetCondMeanType() == theMeanEnum) ;
		}
		else
			return false ;
	}

	/*!
	 * \fn void cRegArchModel::PrintMean(ostream& theOut) const
	 * \param ostream& theOut: output stream (screen or file). Default: cout
	 */
	void cRegArchModel::PrintMean(ostream& theOut) const
    {	if (mMean != NULL)
    		mMean->Print(theOut) ;
    }

	/*!
	 * \fn int cRegArchModel::GetNVar(void)
	 * \param void
	 * \details return the number of variance components
	 */
	int cRegArchModel::GetNVar(void)
	{

	{
		// complete
	}

	/*!
	 * \fn void cRegArchModel::PrintVar(ostream& theOut) const
	 * \param ostream& theOut: output stream (screen or file). Default: cout
	 */
	void cRegArchModel::PrintVar(ostream& theOut) const
    {	
		if (mVar != NULL)
    		mVar->Print(theOut);
    }

	/*!
	 * \fn void cRegArchModel::SetResid(cAbstResiduals& theCondResiduals)
	 * \param cAbstResiduals& theCondResiduals: the conditional residuals model
	 */
	void cRegArchModel::SetResid(cAbstResiduals& theCondResiduals)
	{
		// complete
	}

	 cRegArchModel::GetResid(void)
	{
		// complete
	}

	/*!
	 * \fn void cRegArchModel::PrintResiduals(ostream& theOut) const
	 * \param ostream& theOut: output stream (screen or file). Default: cout
	 */
	void cRegArchModel::PrintResiduals(ostream& theOut) const
    {	if (mResids != NULL)
    		mResids->Print(theOut) ;
    }

	/*!
	 * \fn void cRegArchModel::Print(ostream& theOut) const
	 * \param ostream& theOut: output stream (screen or file). Default: cout
	 */
	void cRegArchModel::Print(ostream& theOut) const
    {
    	theOut << "Regression with ARCH type residuals parameters:" << endl ;
    	theOut << "-----------------------------------------------" << endl ;
    	PrintResiduals(theOut) ;
    	theOut << endl ;
    	PrintMean(theOut) ;
    	theOut << endl ;
    	PrintVar(theOut) ;
    	theOut << endl ;
    
    }

	uint cRegArchModel::GetNParam(void) const
    {
    	if (mMean != NULL)
    		return mMean->GetNParam() + mVar->GetNParam() + mResids->GetNParam() ;
    	else
    		return mVar->GetNParam() + mResids->GetNParam() ;
    }


}//namespace

