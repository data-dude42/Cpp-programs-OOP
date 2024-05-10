/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <iomanip>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char *name, bool checking)
	{
		m_userName[0] = '\0'; // Empty string implies is account is not open
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char *name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods

	bankAccount::operator bool() const
	{
		return isOpen();
	}

	bankAccount::operator double() const
	{
		return m_funds;
	}

	bankAccount &bankAccount::operator++()
	{
		if (m_funds > 0 && isOpen())
		{
			if (m_checking)
			{
				m_funds += m_funds * CHECKING_INTEREST_RATE;
			}
			else
			{
				m_funds += m_funds * SAVINGS_INTEREST_RATE;
			}
		}
		return *this;
	}

	bankAccount &bankAccount::operator--()
	{
		if (isOpen())
		{
			if (m_checking)
			{
				m_funds -= m_monthlyTransactions * CHECKING_TRANSACTION_FEE;
			}
			else
			{
				m_funds -= m_monthlyTransactions * SAVINGS_TRANSACTION_FEE;
			}
		}
		return *this;
	}

	bool bankAccount::operator+=(double d)
	{
		if (isOpen())
		{
			cout << "Deposit $" << fixed << setprecision(2) << d << " for " << m_userName << endl;
			m_funds += d;
			m_monthlyTransactions++;
			return true;
		}
		return false;
	}

	bool bankAccount::operator-=(double f)
	{
		if (isOpen())
		{
			cout << "Withdraw $" << fixed << setprecision(2) << f << " for " << m_userName << endl;
			m_funds -= f;
			m_monthlyTransactions++;
			return true;
		}
		return false;
	}

	bool bankAccount::operator==(const bankAccount &acc) const
	{
		if (strcmp(m_userName, acc.m_userName) == 0 && (m_funds - acc.m_funds < 0.001) && acc.m_funds - m_funds < 0.001 && m_checking == acc.m_checking)
		{
			return true;
		}
		return false;
	}

	bool bankAccount::operator>(double specifiedValue) const
	{
		if (isOpen())
		{
			if (m_funds > specifiedValue)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	bool bankAccount::operator<=(double bc) const
	{
		return (!(m_funds > bc));
	}

	bool bankAccount::operator<<(bankAccount &sourceAccount)
	{
		if (isOpen() && sourceAccount.isOpen() && sourceAccount.m_funds > 0.0)
		{
			printf("Transfer $%.2lf from %s to %s\n", sourceAccount.m_funds, sourceAccount.m_userName, m_userName);
			*this += sourceAccount.m_funds;
			sourceAccount -= sourceAccount.m_funds;
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}

	void bankAccount::display(void) const
	{
		if (isOpen())
		{

			cout << "Display Account -> User:" << std::setfill('-') << std::setw(16) << std::right
				 << m_userName << " | " << std::setfill(' ') << std::setw(8) << std::right
				 << (m_checking ? "Checking" : "Savings") << " | Balance: $  "
				 << std::setw(6) << std::right << std::fixed << std::setprecision(2) << m_funds
				 << " | Transactions:" << std::setfill('0') << std::setw(3)
				 << m_monthlyTransactions << endl;
		}
		else
		{
			cout << "Display Account -> User:------- NOT OPEN" << endl;
		}
	}

	// ADD: Global Helper Functions

	bool operator>(double lhs, const bankAccount &rhs)
	{
		if (rhs)
		{
			double funds = rhs;
			return lhs > funds;
		}
		return false;
	}

	bool operator<=(double lhs, const bankAccount &rhs)
	{
		return (!(lhs > rhs));
	}

}
