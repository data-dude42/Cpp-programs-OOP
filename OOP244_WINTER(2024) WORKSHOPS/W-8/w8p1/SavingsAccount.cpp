/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date:
// Author:
// Description
// This file implements the SavingsAccount class
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

#include "SavingsAccount.h"

using namespace std;
using namespace seneca;



SavingsAccount::SavingsAccount(double balance, double interest) : Account(balance) {
	if (interest > 0.0) {
		m_InterestRate = interest;
		
	}
	else {
		m_InterestRate = 0.0;
	}
}

void SavingsAccount::monthEnd() {
	credit(balance() * m_InterestRate);
}


void SavingsAccount::display(std::ostream& ostr) const {
         // formatting the output as it given.
	ostr << "Account type: Savings" << endl;
	ostr << "Balance: $" << fixed << setprecision(2) << balance() << endl;
	ostr << "Interest Rate (%): " << fixed << setprecision(2) << m_InterestRate * 100 << endl;


}
