/*
NAME -> PARAS SINGH
STUDENT_ID -> 165-114-232
EMAIL -> psingh721@myseneca.ca
DATE -> 29 MARCH, 2024
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Book.h"

//  this book is derived from libraryitem class, so as its implementations
using namespace std;
namespace seneca {
	Book::Book(const char* title, int year, const char* author):LibraryItem(title, year) { // parameters constructions
		if (author && *author) // 
		{
			delete[] m_author;
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
			
		}
	}


	Book::Book(Book& other):LibraryItem(other) { // copy constructor
		m_author = new char[strlen(other.m_author) + 1];
		strcpy(m_author, other.m_author);
	}


	Book& Book::operator=(Book& other) { // copy assignment
		if (&other != this) {
			LibraryItem::operator=(other);
			delete[] m_author;
			m_author = new char[strlen(other.m_author) + 1];
			strcpy(m_author, other.m_author);
		}
		return *this;
	}

	Book :: ~Book() { // destructor
		delete[] m_author;
		m_author = nullptr;
	}

	ostream& Book::display(ostream& ostr) const {
		LibraryItem::display(ostr);
		ostr << endl;
		ostr << "Author: " << m_author;
		return ostr;
	} // formatted output

	bool Book::operator>(const Book& other) const {
		bool returnValue = true;
		if (other.m_author && other.m_author[0] && m_author && m_author[0]) {
			return m_author[0] > other.m_author[0];
		}
		else {
			returnValue = false;
		}
		return returnValue;
	}  // boolean operator ...

}