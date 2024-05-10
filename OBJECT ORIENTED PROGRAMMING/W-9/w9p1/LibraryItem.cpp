/*
NAME -> PARAS SINGH
STUDENT_ID -> 165-114-232
EMAIL -> psingh721@myseneca.ca
DATE -> 29 MARCH, 2024
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <ostream>

#include "LibraryItem.h"

using namespace std;
namespace seneca { // default constructor
	seneca::LibraryItem::LibraryItem() : m_title{}, m_year{} 
	{} // m_title{} and m_year{} are empty initializers. 
	      // For built-in types like pointers and integers, empty initializers have specific meanings
	     // m_title{} -> initializes it to nullptr and m_year{} -> for an integer initializes to 0.
	    // there is a also a less common approach that is as follows:
	   // m_title = nullptr;
	  // m_year = 0;

	// parameter constructions
	seneca::LibraryItem::LibraryItem(const char* title, int year) { // parameters constructions
		if (title && *title) // 
		{
			delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_year = year;
		}
	}

	LibraryItem::LibraryItem(LibraryItem& library) { //  copy constrcutor
		m_title = new char[strlen(library.m_title) + 1];
		strcpy(m_title, library.m_title);
		m_year = library.m_year;
		
		
	}

	LibraryItem &LibraryItem::operator=(LibraryItem& library) { // copy assignment
		if (&library != this) {
			delete[] m_title;
			m_title = new char[strlen(library.m_title) + 1];
			strcpy(m_title, library.m_title);
			m_year = library.m_year;
		}
		return *this; // this line returns a reference to the current object (*this)
		// assignment is complete. This allows for chaining operations like. book1=book2=book3...

	}

	LibraryItem:: ~LibraryItem() { // destructor
		delete[] m_title;
		m_title = nullptr;
	}

	// ostream
	ostream& LibraryItem::display(ostream& ostr) const {
		ostr << "Title: " << m_title << " (" << m_year << ")";
		return ostr; // formatted output.
	  }

	

}