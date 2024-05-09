/*****************************************************************
						Declaration
Name       : PARAS SINGH
Email      : psingh721@myseneca.ca
StudentID  : 165-115-232
Date       : 24-FEB-2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef HERO_H
#define HERO_H

#include "Power.h"
#include "iostream"

namespace seneca
{

	const int MAX_NAME_LEN = 50; // Maximum length for hero name.

	class Hero
	{

		// Data members.
		char m_hero_name[MAX_NAME_LEN + 1]; // Name of the hero.
		Power *m_powers;					// Pointer to an array of Power objects.
		int m_num_powers;					// Number of powers the hero possesses.
		int m_power_lvl;					// Power level of the hero.

	public:
		// Constructors and Destructor.
		Hero();										   // Default constructor.
		Hero(const char *name, Power *pow, int n_pow); // Constructor with parameters.
		~Hero();									   // Destructor.

		// Member functions.
		void setEmpty();										   // Function to set the hero to an empty state.
		std::ostream &display(std::ostream &os = std::cout) const; // Function to display the hero's information.
		bool isEmpty() const;									   // Function to check if the hero is empty.
		void updatelvl();										   // Function to update the power level of the hero.
		int checkPowerLvl() const;								   // Function to get the power level of the hero.

		// Member operators.
		bool operator+=(Power &pow);  // Operator to add a power to the hero.
		bool operator-=(int pow_lvl); // Operator to decrease the power of the hero.
	};

	// Global operators.
	bool operator<(Hero &lhs, Hero &rhs);	 // Operator to compare power levels (less than).
	bool operator>(Hero &lhs, Hero &rhs);	 // Operator to compare power levels (greater than).
	bool operator>>(Power &pow, Hero &hero); // Operator to add a power to a hero.
	bool operator<<(Hero &hero, Power &pow); // Operator to add a power to a hero in reversed order

}

#endif // !HERO_H
