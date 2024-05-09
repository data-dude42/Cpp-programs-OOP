/*/////////////////////////////////////////////////////////////////////////
                        Workshop-2 Part-1
Full Name  : PARAS SINGH
Student ID#: 165114232
Email      : psingh721@myseneca.ca
Section    : ZEE
Date       : 28/01/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef ASSESSMENTS_H
#define ASSESSMENTS_H

#include <cstdio>
namespace seneca {
    struct Assessment {
        double* m_mark;
        char* m_title;
    };

    bool read(int& value, FILE* fptr);//Reads one integer from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false


    bool read(double& value, FILE* fptr);//Reads one double from the fptr file into the value reference and returns true if it was successful, otherwise, it will return false


    bool read(char* cstr, FILE* fptr);//Skips a comma and then reads a cstring no longer than 60 characters from the fptr file into the address, cstr and returns true if it was successful, otherwise, it will return false


    bool read(Assessment& assess, FILE* fptr);//First, it will try to read a double value for the mark and a string for the title into a temporary local double variable and a 60-character lone cString (+1 for null).


    void freeMem(Assessment*& aptr, int size);//The dynamic array will be deleted by first going through each element of the Assessment array in a loop, deleting the dynamic double and the dynamic cString of all Assessment elements and then it will delete the array itself.


    int read(Assessment*& aptr, FILE* fptr);//This read function receives a reference of an Assessment pointer (to hold a dynamic array) and a file pointer from which it will read the assessment records into a newly allocated dynamic array.The function will first read one integer which is the number of upcoming records to read.
}
#endif // ASSESSMENTS_H
