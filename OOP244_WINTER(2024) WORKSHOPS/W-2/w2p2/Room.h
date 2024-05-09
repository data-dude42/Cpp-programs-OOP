/*/////////////////////////////////////////////////////////////////////////
						Workshop-2 Part-2
Full Name  : PARAS SINGH
Student ID#: 165114232
Email      : psingh721@myseneca.ca
Section    : ZEE
Date       : 02-FEB-2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef ROOM_H
#define ROOM_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Guest.h"
using namespace std;
namespace seneca
{

	struct Room
	{
		char m_roomNumber[6];
		int m_noOfGuests;
		Guest *m_guests;
	};

	// sets the Room by allocating a dynamic array of guests and setting the room number
	// (no validation is done for room number)
	void set(Room &room, int numberOfGuests, const char *roomNumber);

	// Prints the room number and names of the guests in the following lines with four
	// spaces of indentaion
	// See correct_output.txt for the exact format
	void print(const Room &room);

	// Books a room by receiving the room number, number of guests and the guest information.
	// See correct_output.txt for the exact format
	void book(Room &room);

	// vacates the room by dallocating all the memory used.
	void vacate(Room &room);

}

#endif