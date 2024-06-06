

#ifndef SENECA_IO_H
#define SENECA_IO_H
namespace seneca {
	
	void printInt(int value, int fieldWidth); // PRINTS THE int VALUE IN WIDTH OF FIELDWIDTH...
	
	int intDigits(int value); // RETURNS number OF DIGITS IN AN INTEGER...
	
	int getInt(int min, int max);//PERFORMS A FOOL-PROFF INTEGER ENTRY ASSUMING THE USER WILL ONLY ENTER NUMBER VALUES, IF USER ENTERS NON-DIGIT VALUES, THE FUCNTION WILL BE IN AN ENDLESS LOOP...
	
	void goBack(int n); // MOVES THE CURSOR BACKWARDS...
	
	int menu(int noOfSamples); // DISPLAYS THE USER INTERFACE MENU...
	
	void labelLine(int n, const char* label); // IT DRAWS A LINE WITH A LABLE...
	
	void line(int n); // DRAWS A LINE...
}
#endif




