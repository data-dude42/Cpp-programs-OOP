/*
NAME -> PARAS SINGH
STUDENT_ID -> 165-114-232
EMAIL -> psingh721@myseneca.ca
DATE -> 29 MARCH, 2024
*/

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "LibraryItem.h"
namespace seneca {
	class Book : public LibraryItem {
		char* m_author{};

	public:
		Book(const char* title, int year, const char* author); // parameters constructions

		// rule of three(3)
		// 1. copy constructor
		Book(Book& other);
		// 2. copy assignment
		Book& operator=(Book& other);
		// 3. destructor
		virtual ~Book();

		ostream& display(ostream& ostr = cout) const;
		bool operator >(const Book& other)const;
	};
}


















#endif 
































