

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "file.h"
#include "StMark.h"
#include "graph.h"
#include "io.h"
using namespace std;
namespace seneca
{
    const int MAX_GROUPS = 10; // MAXIMUM NUMBER OF GROUPS

    void sortData(StMark m[], int rec_read)
    {
        char fname[50] = {'0'};
        char lname[50] = {'0'};

        for (int i = 0; i < rec_read - 1; i++) // bubble sort algorithm is used here respectively.
        {                                         // this loop goes through the list from the beginning to the end, but it stops one position earlier each time. because last position will already have the highest marks among the reamaining students

            for (int j = 0; j < rec_read - i - 1; j++)
            { // The inner for loop goes  through the list from the beginning to the position where the outer loop stopped. It compares each pair of students and swaps them if the first one has a lower mark than the second one. This way, the highest mark among the unsorted students will move to the end of the list.

                if (m[j].mark < m[j + 1].mark)
                { /*swapping*/
                    int temp = m[j].mark;
                    m[j].mark = m[j + 1].mark;
                    m[j + 1].mark = temp;

                    strcpy(fname, m[j].name); // in this string copy function the name of first student  m[j].name into a local varaible called fname.
                    strcpy(m[j].name, m[j + 1].name);
                    strcpy(m[j + 1].name, fname);

                    strcpy(lname, m[j].surname);
                    strcpy(m[j].surname, m[j + 1].surname);
                    strcpy(m[j + 1].surname, lname);
                }
            }
        }
    }

    /// <summary>
    /// Tries to open the students' mark data file.
    /// If successful it will print a report based on the
    /// date in the file.
    /// </summary>
    /// <param name="filename">, holds the data file name</param>
    /// <returns>True if the date files is opened succesfully,
    /// otherwise returns false</return

    void setmarksdistribution(int rec_read, StMark m[], int mark_dist_[])
    {
        int i = 0; // The while loop is initialized with i = 0, and the loop continues until i is no longer less than recordsRead
        while (i < rec_read)
        {
            if (m[i].mark > 90 && m[i].mark <= 100)
            {
                ++mark_dist_[0];
            }
            else if (m[i].mark > 80 && m[i].mark <= 90)
            {
                ++mark_dist_[1];
            }
            else if (m[i].mark > 70 && m[i].mark <= 80)
            {
                ++mark_dist_[2];
            }
            else if (m[i].mark > 60 && m[i].mark <= 70)
            {
                ++mark_dist_[3];
            }
            else if (m[i].mark > 50 && m[i].mark <= 60)
            {
                ++mark_dist_[4];
            }
            else if (m[i].mark > 40 && m[i].mark <= 50)
            {
                ++mark_dist_[5];
            }
            else if (m[i].mark > 30 && m[i].mark <= 40)
            {
                ++mark_dist_[6];
            }
            else if (m[i].mark > 20 && m[i].mark <= 30)
            {
                ++mark_dist_[7];
            }
            else if (m[i].mark > 10 && m[i].mark <= 20)
            {
                ++mark_dist_[8];
            }
            else if (m[i].mark >= 0 && m[i].mark <= 10)
            {
                ++mark_dist_[9];
            }
            ++i;
        }
    }

    bool printReport(const char *filename)
    {
        int marksdistribution[MAX_NO_RECS] = {0};
        StMark m[MAX_NO_RECS];
        int rec_read = 0;

        if (strcmp(filename, "group1.csv") != 0 && strcmp(filename, "group3.csv") != 0)
        {
            return false;
        }

        openFile(filename);
        rec_read = readMarks(m);
        setmarksdistribution(rec_read, m, marksdistribution);
        printGraph(marksdistribution, MAX_GROUPS, "Students' mark distribution");

        sortData(m, rec_read);

        int i = 0;
        while (i < rec_read)
        {
            if (i < 9)
            {
                cout << (i + 1) << "  : ";
                cout << "[";
                printInt(m[i].mark, 3); // print the int value in width of fieldwidth.
                cout << "] " << m[i].name << " " << m[i].surname << endl;
            }
            else if (i < 99)
            {
                cout << (i + 1) << " : ";
                cout << "[";
                printInt(m[i].mark, 3);// print the int value in width of fieldwidth.
                cout << "] " << m[i].name << " " << m[i].surname << endl;
            }
            else
            {
                cout << (i + 1) << ": ";
                cout << "[";
                printInt(m[i].mark, 3); //print the int value in width of fieldwidth.
                cout << "] " << m[i].name << " " << m[i].surname << endl;
            }
            ++i;
        }
        cout << "----------------------------------------" << endl;
        closeFile();
        return true;
    }
}
