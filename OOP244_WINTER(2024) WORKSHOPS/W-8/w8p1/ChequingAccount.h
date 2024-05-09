/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date:
// Author:
// Description
// This file implements the ChequingAccount class
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

#ifndef SENECA_CHEQUING_ACCOUNT_H
#define SENECA_CHEQUING_ACCOUNT_H

#include "Account.h"

namespace seneca {
	class ChequingAccount : public Account {
		double m_TransactionFee; // for holding transaction fees
		double m_MonthlyFee; // for holding monthly fees

	public:
		ChequingAccount(double, double, double); // constructor for holding acc. balance, transaction fee, month-end fee in the double variable data type.
		virtual bool credit(double); // modifier to credits the balance by the amount recieved 
		virtual bool debit(double); // modifier to debits the balance by the amount recieved
		virtual void monthEnd(); // modifier that debits the monthly fee from the balance
		virtual void display(std::ostream&) const;// ostream the format output
	};
}

#endif // !SENECA_CHEQUING_ACCOUNT_H



