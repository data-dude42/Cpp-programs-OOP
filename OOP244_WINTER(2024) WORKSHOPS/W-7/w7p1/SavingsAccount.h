/*****************************************************************
                        Declaration
Name       : PARAS SINGH
Email      : psingh721@myseneca.ca
Student_ID : 165-114-232
Date       : 21 march 2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "BankAccount.h"

namespace seneca
{
    class SavingsAccount : public BankAccount
    { // SavingsAccount class inherits from BankAccount class
        // Data members
        double m_interest;
        Date m_interestDate;
        void writeInterest(std::ostream &out) const;

    public:
        // Public member functions
        SavingsAccount(const char *name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
        void applyInterest(Date &dt);
        std::ostream &write(std::ostream &out) const;
        std::istream &read(std::istream &in);
    };
    // Helper functions
    std::istream &operator>>(std::istream &in, SavingsAccount &acct);
    std::ostream &operator<<(std::ostream &out, const SavingsAccount &acct);
}
#endif // !SENECA_SAVINGSACCOUNT_H