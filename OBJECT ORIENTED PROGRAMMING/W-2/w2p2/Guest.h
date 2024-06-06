#ifndef GUEST_H
#define GUEST_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace seneca
{

	struct Guest
	{
		char *m_firstName;
		char *m_lastName;
		bool m_adult;

		// initialize all pointers to nullptr and setting.
		Guest() : m_firstName(nullptr), m_lastName(nullptr) {}
	};

	// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
	void set(Guest &guest, const char *first, const char *last, int age);

	// Prints the guest name:
	// "Name Surname(child)"
	// The child flag is printed if the guest is not an adult
	// and if the names are not set, "Vacated!" is printed.
	void print(const Guest &guest);

	// books the guest information from the console:
	// Name: Jake<ENTER>
	// Lastname: Doe<ENTER>
	// Age: 10<ENTER>
	void book(Guest &guest);

	// vacates the guest by dallocating its memory.
	void vacate(Guest &guest);
}

#endif
