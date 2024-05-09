/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: iAccount.h
// Version 1.0
// Date:
// Author:
// Description
// This file defines the iAccount interface
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
/*****************************************************************/



/*
Name -> "PARAS SINGH"
Student_ID -> 165-114-232
Email -> psingh721@myseneca.ca
Date- 25 march, 2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/


#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H

#include <iostream> // including all the macrodirectives .....
#include <iomanip>


namespace seneca {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() = default;

	};

	iAccount* CreateAccount(const char*, double);

}
#endif // !SENECA_IACCOUNT_H
