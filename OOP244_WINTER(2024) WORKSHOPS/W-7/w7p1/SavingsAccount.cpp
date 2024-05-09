/*****************************************************************
						Declaration
Name       : PARAS SINGH
Email      : psingh721@myseneca.ca
Student_ID : 165-114-232
Date       : 21 march 2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "SavingsAccount.h"
#include <iostream>
#include "iomanip"

using namespace std;
using namespace seneca;

// writeInterest function displays the interest rate in a formatted manner
void SavingsAccount::writeInterest(std::ostream &out) const
{
	out << setprecision(3) << fixed << m_interest << "%";
}

// SavingsAccount constructor with bankAccount constructor
SavingsAccount::SavingsAccount(const char *name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance)
{
	m_interest = interest;
	m_interestDate = interestDate;
}

// applyInterest function applies the interest to the balance
void SavingsAccount::applyInterest(Date &dt)
{
	double interestAmount;				   // variable to store the interest amount
	double balance = getBalance();		   // getting the balance
	interestAmount = balance * m_interest; // calculating the interest amount
	cout << "   ";
	writeCurrency(cout, balance);
	cout << " + $" << interestAmount << " (";
	writeInterest(cout);
	cout << ")"
		 << " = ";
	balance += interestAmount; // adding the interest to the balance
	setBalance(balance);	   // setting the balance to the new balance with the interest
	writeCurrency(cout, balance);
	cout << " | ";
	m_interestDate.write(cout);
	cout << " => ";
	m_interestDate = dt;
	m_interestDate.write(cout);
	cout << endl;
}

// write function displays the savings account information in a formatted manner
std::ostream &SavingsAccount::write(std::ostream &out) const
{

	BankAccount::write(out); // calling the write function from the BankAccount class
	out << " | ";
	writeInterest(out); // calling the writeInterest function for the SavingsAccount class
	out << " | " << m_interestDate;
	return out;
}

// read function inputs the savings account information from the user
std::istream &SavingsAccount::read(std::istream &in)
{

	in.ignore(10, '\n');
	BankAccount::read(in); // calling the read function from the BankAccount class
	cout << "Interest Date ";
	m_interestDate.read(in); // calling the read function from the Date class
	cout << "Interest Rate: ";
	in >> m_interest;
	return in;
}

// operator>> function overloads the input operator for the SavingsAccount class
std::istream &seneca::operator>>(std::istream &in, SavingsAccount &acct)
{
	acct.read(in);
	return in;
}

// operator<< function overloads the output operator for the SavingsAccount class
std::ostream &seneca::operator<<(std::ostream &out, const SavingsAccount &acct)
{
	acct.write(out);
	return out;
}