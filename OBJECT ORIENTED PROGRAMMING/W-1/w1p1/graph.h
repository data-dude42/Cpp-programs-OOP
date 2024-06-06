

#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H
namespace seneca {
	
	void getSamples(int samples[], int noOfSamples); // FILLS THE SAMPLES ARRAY WITH THE STATISTIC SAMPLES...
	
	int findMax(int samples[], int noOfSamples); // FINDS THE LARGEST SAMPLE IN THE SAMPLES ARRAY, IF IT IS GREATER THAN GW, OTHERWISE IT WILL RETURN GW  (GW= grapwidth)...
	
	void printBar(int val, int max); // PRINTS A SCALED BAR RELEVANT TO THE MAXIMUM VALUE IN SAMPLES ARRAY...
	
	void printGraph(int samples[], int noOfSamples, const char* label); // PRINTS A GRAPH COMPARING THE SAMPLE VALUES...
}
#endif
