/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_

namespace seneca
{
   const int ACCT_MAXLEN_USER = 16; // Max Length of user name

   // Class Definition
   class bankAccount
   {

   private:
      // Data Members
      char m_userName[ACCT_MAXLEN_USER];
      double m_funds;
      bool m_checking;
      int m_monthlyTransactions;

      bool isOpen() const;

   public:
      bankAccount(const char *name = nullptr, bool checking = false);
      bool setup(const char *name, bool checking);

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods

      // CAST OPERATOR...
      operator bool() const; // Returns true if the account isOpen(); false otherwise. This method does not modify the object.

      operator double() const; // Returns the total $ funds held in the account. Does not modify the object

      // UNARY OPERATOR...
      bankAccount &operator++(); // Calculates interest (ie: funds x rate) and adds it to existing funds in the account. Note the rate is based on the account type (see Fees & Interest above). Interest can only be earned for accounts which have a positive value and have been opened. Returns reference to the current object.

      bankAccount &operator--(); // Calculates fees (ie: Monthly transactions multiplied by transaction fee) and subtracts it from existing funds in the account. Note the transaction fee is based on the account type (see Fees & Interest above). Can only be used if the account has been opened. Returns reference to the current object.

      // BINARY OPERATOR
      bool operator+=(double); // Deposits specified value by adding it to existing funds and increments the number of transactions. operator+= Can only be used if the account has been opened. This method returns true on success; false otherwise.

      bool operator-=(double); // Withdraws specified value by subtracting it from existing funds and increments the number of transactions. It can only be used if the account has been opened. It returns true on success and outputs sample text below; false otherwise. It can be implemented by simply multiplying the specified value by -1 and invoking operator+= above.

      bool operator==(const bankAccount &) const; // Operator== checks if the specified bank account has the same user name, funds and type as this. It returns true if all 3 are identical; false otherwise. This method does not modify the object.

      bool operator>(double) const; // Returns true if funds in account > specified value. operator> can only be used if the account has been opened. This method does not modify the object.

      bool operator<=(double) const; // Returns true if funds in account <= specified value. It can only be used if the account has been opened. operator<= Does not modify the object. It can be implemented by simply invoking operator> from above and reversing the result.

      // ADDITIONAL METHODS...

      bool operator<<(bankAccount & acc); // transfer all funds from the specified account to this account. First, check if both this account and the source account are open, and if the source account has positive funds. Then display Formatted output as per the example below. Finally use operator+= and operator-= (ie: what you just implemented above) to perform a transfer of funds. This method returns true on success; false otherwise.

      void display(void) const; // Display formatted output for this object as per the sample output below.
      // GIVEN DETAILS...

      const double CHECKING_TRANSACTION_FEE = 1.25;
      const double CHECKING_INTEREST_RATE = 0.005;
      const double SAVINGS_TRANSACTION_FEE = 3.50;
      const double SAVINGS_INTEREST_RATE = 0.025;
   };

   // ADD: Global helpers
   bool operator>(double lhs, const bankAccount &rhs); // You will need to implement this global helper operator to support the case where the lhs (ie: left operand) is not a class (it is a primitive data type) and therefore not capable of having a method. Use the (bool) cast operator to confirm the rhs account is open and the (double) cast operator to get the funds from the rhs account, then return the result of the comparison.

   bool operator<=(double lhs, const bankAccount &rhs); // This global helper is required for the same reasons as above. It can be implemented by simply invoking the above global helper operator> and reversing the result.
}
#endif
