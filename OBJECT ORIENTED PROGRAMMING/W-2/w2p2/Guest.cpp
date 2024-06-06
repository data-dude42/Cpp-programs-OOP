#include "Guest.h"
using namespace std;
using namespace seneca;
int const buff = 100; // declaring the buffer size in the initial part of the code for code resuability...
// sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
void seneca::set(Guest &guest, const char *first, const char *last, int age)
{

	// It checks if the pointer m_firstName is not null, which means it already points to some memory location that contains the guest’s first name.
	if (guest.m_firstName != nullptr)
	{
		delete[] guest.m_firstName; // If the pointer is not null, it uses the delete [] operator to deallocate the memory that was allocated for the char array. This frees up the memory and avoids memory leaks.
		guest.m_firstName = nullptr;
	}

	{ // It checks if the pointer m_lastName is not null, which means it already points to some memory location that contains the guest’s last name.
		if (guest.m_lastName != nullptr)
		{
			delete[] guest.m_lastName; // if the pointer is not null, it uses the delete [] operator to deallocate the memory that was allocated for the char array. This frees up the memory and avoids memory leaks.

			guest.m_lastName = nullptr; // It then assigns the pointer m_lastName to null, which means it does not point to any memory location. This prevents dangling pointers and invalid memory access.
		}
	}

	// Check if given first name pointer is null or empty string
	if (first == nullptr || first[0] == '\0')
	{
		guest.m_firstName = nullptr;
	}
	else
	{
		// Allocate memory for first name
		guest.m_firstName = new char[strlen(first) + 1];
		strcpy(guest.m_firstName, first); // Copy the name to the struct
	}

	// Check if given last name pointer is null or empty string
	if (last == nullptr || last[0] == '\0')
	{
		guest.m_lastName = nullptr;
	}
	else
	{
		// Allocate memory for last name
		guest.m_lastName = new char[strlen(last) + 1];
		strcpy(guest.m_lastName, last); // Copy the last name to the struct
	}

	// Set m_adult flag based on age
	guest.m_adult = (age >= 18);
}

// Prints the guest name:
// "Name Surname(child)"
// The child flag is printed if the guest is not an adult
// and if the names are not set, "Vacated!" is printed.
void seneca::print(const Guest &guest)
{

	if (guest.m_firstName == nullptr || guest.m_lastName == nullptr)
	{
		cout << "Vacated!" << endl;
		return;
	}

	cout << guest.m_firstName << " " << guest.m_lastName;

	if (!guest.m_adult)
	{
		cout << "(Child)";
	}
	cout << endl;
}

// books the guest information from the console:
// Name: Jake<ENTER>
// Lastname: Doe<ENTER>
// Age: 10<ENTER>
void seneca::book(Guest &guest)
{

	// Temporary buffers to hold input from the console
	char first_buff[buff];
	char last_buff[buff];
	int age;

	// Prompting for the first name
	cout << "Name: ";
	cin.getline(first_buff, buff);

	// Prompting for last name
	cout << "Lastname: ";
	cin.getline(last_buff, buff);

	// Prompting age.. .  
	cout << "Age: ";
	cin >> age;
	cin.ignore(); // it will ignore the newline character in the input buffer.

	// Sets guest variables and the m_adult flag from the inputs
	set(guest, first_buff, last_buff, age);
}

// vacates the guest by deallocating its memory.
void seneca::vacate(Guest &guest)
{
	// deallocating mem. for the first name...
	if (guest.m_firstName != nullptr)
	{
		delete[] guest.m_firstName;
		guest.m_firstName = nullptr;
	}

	// doing the same for the last name...
	if (guest.m_lastName != nullptr)
	{
		delete[] guest.m_lastName;
		guest.m_lastName = nullptr;
	}

	// reset the adult flag...
	guest.m_adult = false;
}
