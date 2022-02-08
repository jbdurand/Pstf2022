#include "StdAfxRegArchLib.h"
/*!
	\file RegArchCompute.cpp
	\brief implementation of the Simulation / Estimation procedures for general RegArchModel
	
	\author Jean-Baptiste DURAND, Ollivier TARAMASCO 
	\date dec-18-2006 - last change feb-18-2011
*/
namespace RegArchLib {

	/*!
	 * \fn void RegArchSimul(uint theNSample, const cRegArchModel& theModel, cRegArchValue& theData)
	 * \param uint theNSample: size of the sample
	 * \param const cRegArchModel& theModel: the RegArch model
	 * \param cRegArchValue& theData: output parameter. The Y(t) values are stored in theData.mYt
	 */
	void RegArchSimul(uint theNSample, const cRegArchModel& theModel, cRegArchValue& theData)
	{
		// A completer
	}

	/*!
	 * \fn double RegArchLLH(const cRegArchModel& theParam, cDVector* theYt, cDMatrix* theXt)
	 * \param const cRegArchModel& theParam: the model
	 * \param cDVector* theYt: the observations
	 * \param cDMatrix* theXt: the regressors matrix. Default NULL
	 * \brief return the log-likelihood value
	 */
	double RegArchLLH(const cRegArchModel& theParam, cDVector* theYt, cDMatrix* theXt)
	{
	cRegArchValue myValue(theYt, theXt) ;
		return RegArchLLH(theParam, myValue) ;
	}

	/*!
	 * \fn double RegArchLLH(const cRegArchModel& theParam,cRegArchValue& theData)
	 * \param const cRegArchModel& theParam: the model
	 * \param cRegArchValue& theData: theData.mYt contains the observations.
	 * \brief return the log-likelihood value
	 */
	double RegArchLLH(const cRegArchModel& theParam, cRegArchValue& theData)
	{
            // A completer
	}

	/*!
	 * \fn void RegArchGradLt(int theDate, cRegArchModel& theParam, cRegArchValue& theValue, cRegArchGradient& theGradData, cDVector& theGradlt)
	 * \brief Compute the gradient of the log-likelihood, at current time theDate
	 * \param int theDate: time at which conditional log-density is considered
	 * \param const cRegArchModel& theParam: the model
	 * \param cRegArchValue& theValue: contains the observations. Used to stored computed residuals, standardized residuals, etc.
	 * \param cRegArchGradient& theGradData: contains the gradient of different components of the model, at current time theDate
	 * \param cDVector& theGradlt: gradient of the log-likelihood, at current time theDate
	 */

	void RegArchGradLt(uint theDate, cRegArchModel& theParam, cRegArchValue& theValue, cRegArchGradient& theGradData, cDVector& theGradlt)
	{	
            // A completer
	}


	/*!
	 * \brief Compute the gradient of the log-likelihood
	 * \fn void RegArchGradLLH(cRegArchModel& theParam, cRegArchValue& theData, cDVector& theGradLLH)
	 * \param const cRegArchModel& theParam: the model
	 * \param cRegArchValue& theData: contains the observations. Used to stored computed residuals, standardized residuals, etc.
	 * \param cDVector& theGradLLH: gradient of the log-likelihood
	 */
	void RegArchGradLLH(cRegArchModel& theParam, cRegArchValue& theData, cDVector& theGradLLH)
	{
            // A completer
	}


	void NumericRegArchGradLLH(cRegArchModel& theModel, cRegArchValue& theValue, cDVector& theGradLLH, double theh)
	{
            // A completer
	}

} //namespace
