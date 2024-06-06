#include "Room.h"

using namespace std;
using namespace seneca;

// sets the Room by allocating a dynamic array of guests and setting the room number
// (no validation is done for room number)
void seneca::set(Room &room, int numberOfGuests, const char *roomNumber)
{
	// Set room number
	strcpy(room.m_roomNumber, roomNumber);

	// Allocating mem for guests.....................
	room.m_noOfGuests = numberOfGuests;
	room.m_guests = new Guest[numberOfGuests];

	// initialization to the null-pointer
	for (int i = 0; i < numberOfGuests; ++i)
	{
		room.m_guests[i].m_firstName = nullptr;
		room.m_guests[i].m_lastName = nullptr;
	}
}

// Prints the room number and names of the guests in the following lines with four
// spaces of indentation
// See correct_output.txt for the exact format
void seneca::print(const Room &room)
{
	// Printing guest names...............
	if (room.m_guests == nullptr)
	{
		cout << "Empty Room!" << endl;
	}
	else
	{
		// Printing room number
		cout << "Room Number: " << room.m_roomNumber << endl;

		for (int i = 0; i < room.m_noOfGuests; ++i)
		{
			cout << "    ";
			print(room.m_guests[i]); // Prints guest info
		}
	}
}

// Books a room by receiving the room number, number of guests and the guest information.
// See correct_output.txt for the exact format
void seneca::book(Room &room)
{
	// temp buffers....
	char roomNumber[6];
	int no_guests;

	// prompting the room number....
	cout << "Room number: ";
	cin.getline(roomNumber, 6);

	// Prompting the number of guests...
	cout << "Number of guests: ";
	cin >> no_guests;
	cin.ignore(); // Ignore the newline character left in the input buffer

	// Setting room information
	set(room, no_guests, roomNumber);

	// Booking guests
	for (int i = 0; i < no_guests; ++i)
	{
		cout << i + 1 << ":" << endl;
		book(room.m_guests[i]);
	}
}

// vacates the room by deallocating all the memory used.
void seneca::vacate(Room &room)
{
	// Deallocate memory for each guest
	for (int i = 0; i < room.m_noOfGuests; ++i)
	{
		Guest &guest = room.m_guests[i];
		delete[] guest.m_firstName;
		guest.m_firstName = nullptr;

		delete[] guest.m_lastName;
		guest.m_lastName = nullptr;
	}

	// Deallocate memory for the array of guests
	delete[] room.m_guests;
	room.m_guests = nullptr;
	room.m_noOfGuests = 0;
}
