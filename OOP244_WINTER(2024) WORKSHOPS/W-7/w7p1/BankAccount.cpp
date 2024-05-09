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

#include "BankAccount.h"
#include <iostream>
#include "iomanip"
#include "cstring"

using namespace std;
using namespace seneca;

// getBalance function
double BankAccount::getBalance() const
{
	return m_balance;
}

// setBalance function
void BankAccount::setBalance(double balance)
{
	m_balance = balance;
}

// writeCurrency function writes the amount in currency format
void BankAccount::writeCurrency(ostream &out, double amount) const
{
	out << '$' << setprecision(2) << fixed << amount;
}

// BankAccount constructor
BankAccount::BankAccount(const char *name, Date openDate, DepositInfo depInfo, double balance)
{
	strncpy(m_name, name, MAX_NAME);
	m_date = openDate;
	m_depInfo = depInfo;
	m_balance = balance;
}

// write function writes the bank account information in a formatted manner
std::ostream &BankAccount::write(std::ostream &out) const
{
	out << ">> " << m_name << " | ";
	writeCurrency(out, m_balance); // calling the writeCurrency function for the formatted output
	out << " | ";
	m_date.write(out); // calling the write function from the Date class
	out << " | ";
	m_depInfo.write(out); // calling the write function from the DepositInfo class
	return out;
}

// read function reads the bank account information from the user
std::istream &BankAccount::read(std::istream &in)
{
	cout << "Name: ";
	in.getline(m_name, MAX_NAME);
	cout << "Opening Balance: ";
	in >> m_balance;
	in.ignore(10, '\n');
	cout << "Date Opened ";
	m_date.read(in);	// calling the read function from the Date class
	m_depInfo.read(in); // calling the read function from the DepositInfo class
	return in;
}

// operator>> function makes use of the read function to input the bank account information
std::istream &seneca::operator>>(std::istream &in, BankAccount &acct)
{
	acct.read(in);
	return in;
}
// operator<< function makes use of the write function to display the bank account information
std::ostream &seneca::operator<<(std::ostream &out, const BankAccount &acct)
{
	acct.write(out);
	return out;
}