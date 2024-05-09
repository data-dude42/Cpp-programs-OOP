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


#include"ChequingAccount.h"


using namespace std;
using namespace seneca;


ChequingAccount::ChequingAccount(double balance, double transfee, double monthlyfee) : Account(balance) {
	if (transfee > 0.0) {
		m_TransactionFee = transfee;
	}
	else {
		m_TransactionFee = 0.0;
	}
	if (monthlyfee > 0.0) {
		m_MonthlyFee = monthlyfee;
	}
	else {
		m_MonthlyFee = 0.0;
	}
}

bool ChequingAccount::credit(double deposit) {
	bool successFull = Account::credit(deposit);
	if (successFull) {
		Account::debit(m_TransactionFee);
	}
	return successFull;

}

bool ChequingAccount::debit(double withdrawn) {
	bool successFull = Account::debit(withdrawn); // call the function from account class and implmenting the instructions as given that is return true if trans. is successfull. 
	if (successFull) {
		Account::debit(m_TransactionFee);
	}
	return successFull;
}


void ChequingAccount::monthEnd() {
	Account::debit(m_MonthlyFee);
}


void ChequingAccount::display(std::ostream& ostr) const {
               // fomattinf the output as per the requirement.
	ostr << "Account type: Chequing" << endl
		<< "Balance: $" << setprecision(2) << fixed << balance() << endl
		<< "Per Transaction Fee: " << setprecision(2) << fixed << m_TransactionFee << endl
		<< "Monthly Fee: " << setprecision(2) << fixed << m_MonthlyFee << endl;
}





