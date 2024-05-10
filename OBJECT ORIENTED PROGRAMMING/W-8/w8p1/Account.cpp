/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date:
// Author:
// Description
// This file implements the Account class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/



/*
Name -> "PARAS SINGH"
Student_ID -> 165-114-232
Email -> psingh721@myseneca.ca
Date- 26 march, 2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/




#include "Account.h"
using namespace std;
using namespace seneca;

	Account::Account(double balance) {
		// validates the initial balance 
		if (balance < 0.0) {
			m_CurrentBalance = 0.0;
		}
		else {
			m_CurrentBalance = balance;
		}
	}


	bool Account::credit(double credit) {
		if (credit > 0.0) {
			m_CurrentBalance += credit;
			return true;
		}
		else {
			return false;
		}

	}

	bool Account::debit(double debit) {
		if (debit > 0.0) {
			m_CurrentBalance -= debit;
			return true;
		}
		else {
			return false;
		}
	}

	double Account::balance() const {
		return m_CurrentBalance;
	}