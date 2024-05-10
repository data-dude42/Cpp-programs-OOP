/*/////////////////////////////////////////////////////////////////////////
						Workshop-1 Part-2
Full Name  : PARAS SINGH
Student ID#: 165114232
Email      : psingh721@myseneca.ca
Section    : ZEE
Date       : 25/01/2024


Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include "file.h"
#include "StMark.h"
using namespace std;
namespace seneca {
   std::FILE* datafile = nullptr;
   bool openFile(const char* fname)
   {
      if (datafile != nullptr) closeFile();
      datafile = fopen(fname, "r");
      return datafile != nullptr;
   }

   void closeFile(){
      if (datafile) {
         fclose(datafile);
         datafile = nullptr;
      }
   }

   bool readMark(StMark* markRec)
   {
      return fscanf(datafile, "%[^,],%[^,],%d\n", markRec->name, markRec->surname, &markRec->mark) == 3;
   }

   int readMarks(StMark* marks)
   {
      int cnt = 0;
      for (; cnt < MAX_NO_RECS && readMark(&marks[cnt]); cnt++);
      return cnt;
   }
}