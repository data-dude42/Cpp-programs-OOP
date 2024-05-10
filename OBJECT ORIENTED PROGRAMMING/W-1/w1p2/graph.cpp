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

#include <iostream>
#include "io.h"
#include "graph.h"
using namespace std;

namespace seneca {
    const int GRAPH_WIDTH = 65;
    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            line(28);
            cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }

    // finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
    // otherwise it will return GRAPH_WIDTH. 
    int findMax(int samples[], int noOfSamples) {
        int maxVal = samples[0];
        int i = 1;
        for (i = 1; i < noOfSamples; i++) {
            if (maxVal < samples[i]) {
                maxVal = samples[i];
            }
        }
        return maxVal;
    }

    // prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }

    // prints a graph comparing the sample values visually 
    void printGraph(int samples[], int noOfSamples, const char* label) {
        int num = 100;
        int max = findMax(samples, noOfSamples);
        labelLine(GRAPH_WIDTH, label);
        for (int i = 0; i < noOfSamples; i++) {
            printInt(num, 4);
            printBar(samples[i], max);
            num -= 10;
        }
        line(GRAPH_WIDTH + 14);
    }   
}