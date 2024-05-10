/*/////////////////////////////////////////////////////////////////////////
						Workshop-1 Part-1
Full Name  : PARAS SINGH
Student ID#: 165114232
Email      : psingh721@myseneca.ca
Section    : ZEE
Date       : 20/01/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H
namespace seneca {
	
	void getSamples(int samples[], int noOfSamples); // FILLS THE SAMPLES ARRAY WITH THE STATISTIC SAMPLES...
	
	int findMax(int samples[], int noOfSamples); // FINDS THE LARGEST SAMPLE IN THE SAMPLES ARRAY, IF IT IS GREATER THAN GW, OTHERWISE IT WILL RETURN GW  (GW= grapwidth)...
	
	void printBar(int val, int max); // PRINTS A SCALED BAR RELEVANT TO THE MAXIMUM VALUE IN SAMPLES ARRAY...
	
	void printGraph(int samples[], int noOfSamples, const char* label); // PRINTS A GRAPH COMPARING THE SAMPLE VALUES...
}
#endif