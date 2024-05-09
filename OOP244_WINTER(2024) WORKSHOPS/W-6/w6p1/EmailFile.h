/*
NAME -> PARAS SINGH
STUDENT ID -> 165-114-232
EMAIL -> psingh721@myseneca.ca
SECTION -> ZEE
*/

#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca
{

	const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record

	class EmailFile;
	class Email
	{
		char *m_email{nullptr};
		char *m_name{nullptr};
		char m_year[5]{'\0'};
		Email(){};
		Email &operator=(const Email &);
		bool load(std::ifstream &in);
		~Email();
		// Prohibit the copy constructor for this class:
		Email(const Email &);
		// Make the EmailFile class a "friend" of the Email class
		friend class EmailFile;
	};

	class EmailFile
	{
		Email *m_emailLines{nullptr};
		char *m_filename{};
		int m_noOfEmails{0};
		void setFilename(const char *filename);
		void setEmpty();
		bool setNoOfEmails();

	public:
		// Constructors
		EmailFile();
		EmailFile(const char *filename);
		// Copy-Constructor
		EmailFile(const EmailFile &other);
		~EmailFile(); // Destructor

		void loadEmails();

		// Type-conversion overloads
		operator bool() const;

		void operator=(const EmailFile &other);
		bool saveToFile(const char *filename) const;
		std::ostream &view(std::ostream &ostr) const;
		void fileCat(const EmailFile &obj, const char *name = nullptr);
	};

	std::ostream &operator<<(std::ostream &ostr, const EmailFile &text);

}
#endif // !SENECA_EMAILFILE_H