#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Room.h"
#include "Guest.h"
using namespace std;
using namespace seneca;


int main() {
   cout << "Testing Guest Functiosn:" << endl;
   Guest G;
   cout << "\nTesting bad setting\n---------------" << endl;
   set(G, nullptr, "ABC", 10);
   print(G);
   set(G, "ABC", nullptr, 10);
   print(G);
   set(G, "", "ABC", 10);
   print(G);
   set(G, "ABC", "", 10);
   print(G);
   cout << "\nTesting Good setting\n---------------" << endl;
   set(G, "Jane", "Doe", 30);
   print(G);
   vacate(G);
   print(G);
   cout << "------------------------" << endl 
        <<"\nTesting Guest booking:\n--- Enter the following:" << endl
      << "Jake\nDoe\n10" << endl 
      << "------------------------" << endl;
   book(G);
   print(G);
   vacate(G);
   print(G);
   cout << "\nTesting Room Functions: " << endl;
   Room A;
   set(A, 2, "A1010");
   print(A);
   vacate(A);
   print(A);
   cout << "------------------------" << endl 
      << "Testing Room booking:\n--- Enter the following:" << endl
      << "A1010\n2\nJane\nDoe\n30\nJake\nDoe\n10" << endl 
      << "------------------------" << endl;
   book(A);
   cout << "\nRoom booking data:" << endl
        << "------------------------" << endl;
   print(A);
   cout << "\nPrinting vacated Room:" << endl
      << "------------------------" << endl;
   vacate(A);
   print(A);
   return 0;
}



