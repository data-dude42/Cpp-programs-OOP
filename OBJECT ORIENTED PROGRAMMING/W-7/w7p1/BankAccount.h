/*****************************************************************
                        Declaration
Name       : PARAS SINGH
Email      : psingh721@myseneca.ca
Student_ID : 165-114-232
Date       : 21 march 2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

#include "DepositUtility.h"

namespace seneca
{

    const int MAX_NAME = 51;

    class BankAccount
    {
        // Data members
        char m_name[MAX_NAME] = {'\0'};
        Date m_date;
        DepositInfo m_depInfo;
        double m_balance;

    protected:
        // Protected member functions
        double getBalance() const;
        void setBalance(double balance);
        void writeCurrency(std::ostream &out, double amount) const;

    public:
        // Public member functions
        BankAccount(const char *name, Date openDate, DepositInfo depInfo, double balance);
        virtual std::ostream &write(std::ostream &out) const;
        virtual std::istream &read(std::istream &in);
    };
    // Helper functions
    std::istream &operator>>(std::istream &in, BankAccount &acct);
    std::ostream &operator<<(std::ostream &out, const BankAccount &acct);
}

#endif // !SENECA_BANKACCOUNT_H
