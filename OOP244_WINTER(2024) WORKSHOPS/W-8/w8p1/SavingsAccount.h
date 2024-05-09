/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:
// Author:
// Description
// This file defines the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
/*****************************************************************/


/*
Name -> "PARAS SINGH"
Student_ID -> 165-114-232
Email -> psingh721@myseneca.ca
Date- 26 march, 2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/



#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H


#include "Account.h"


namespace seneca {
	class SavingsAccount : public Account {
		double m_InterestRate; // a double for holding interest rate.

	public:
		SavingsAccount(double, double);
		virtual void monthEnd();
		virtual void display(std::ostream&) const;
	};
}
#endif // !SENECA_SAVINGS_ACCOUNT_H
