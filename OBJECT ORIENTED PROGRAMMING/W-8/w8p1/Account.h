/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date:
// Author:
// Description
// This file defines the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
/************************************************************************
Name -> "PARAS SINGH"
Student_ID -> 165-114-232
Email -> psingh721@myseneca.ca
Date- 26 march, 2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************/



#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include "iAccount.h"

namespace seneca {
	class Account : public iAccount {   ///////////////////////
		double m_CurrentBalance;

	    public:

		Account(double balance = 0.0);
		virtual bool credit(double);
		virtual bool debit(double);
		virtual ~Account() = default;

	   protected:
		   virtual double balance() const;

	};
}


#endif // !SENECA_ACCOUNT_H