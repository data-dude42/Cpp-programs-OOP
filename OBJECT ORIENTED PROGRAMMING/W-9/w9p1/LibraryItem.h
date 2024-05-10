/*
NAME -> PARAS SINGH
STUDENT_ID -> 165-114-232
EMAIL -> psingh721@myseneca.ca
DATE -> 29 MARCH, 2024
*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream> // using the standard library
#include "LibraryItem.h"

using namespace std;
namespace seneca {
	class LibraryItem { // data members
		char* m_title{};
		int m_year{};

	public: // member functions
		LibraryItem();
		LibraryItem(const char* title, int year);// parameterzed constructor(that would accept a two parameters character title and year.)
		// now making the rule of three

		// 1. copy constructor
		LibraryItem(LibraryItem& library);
		// 2. copy assignment
		LibraryItem& operator=(LibraryItem& library);
		// 3. destructor
		virtual ~LibraryItem();

		// output stream
		virtual ostream& display(ostream& ostr = cout) const;
	};
}



#endif 