
#include <iostream>
#include "iomanip"
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca
{
   // Default constructor for GuitarStr class
   GuitarStr::GuitarStr() {}

   // Constructor for GuitarStr class with parameters for material and gauge
   GuitarStr::GuitarStr(const char *ma, double ga)
   {
      // Copy material to m_material with strncpy to avoid buffer overflow
      strncpy(m_material, ma, MAT_LEN - 1);
      m_material[MAT_LEN - 1] = '\0'; // Ensure null-termination for safety
      m_gauge = ga; // Set gauge
   }

   // Accessor function to get the material of the guitar string
   const char *GuitarStr::material() const
   {
      return m_material; // Return material
   }

   // Accessor function to get the gauge of the guitar string
   double GuitarStr::gauge() const
   {
      return m_gauge; // Return gauge
   }

   // Constructor for Guitar class with model parameter
   Guitar::Guitar(const char *mod) : m_numStrings(0)
   {
      m_strings = nullptr; // Initialize m_strings pointer to nullptr
      strncpy(m_model, mod, 15); // Copy model to m_model with strncpy to avoid buffer overflow
   }

   // Constructor for Guitar class with array of GuitarStr objects, number of strings, and model parameters
   Guitar::Guitar(GuitarStr strs[], int ns, const char *mod)
   {
      // Check for valid input parameters
      if (ns <= 0 || ns > 100 || strlen(mod) > 15)
      {
         m_strings = nullptr; // Set m_strings to nullptr if parameters are invalid
         m_numStrings = 0; // Set number of strings to 0
         return; // Exit constructor
      }

      // Allocate memory for m_strings based on the number of strings
      m_strings = new GuitarStr[ns];
      int i;
      for (i = 0; i < ns; ++i)
      {
         m_strings[i] = strs[i]; // Copy GuitarStr objects from input array to m_strings
      }
      m_numStrings = ns; // Set number of strings
      strncpy(m_model, mod, 15); // Copy model to m_model with strncpy to avoid buffer overflow
   }

   // Destructor for Guitar class, deallocates memory
   Guitar::~Guitar()
   {
      delete[] m_strings; // Deallocate memory for m_strings
   }

   // Method to change a string in the Guitar object given its index
   bool Guitar::changeString(const GuitarStr &gs, int sn)
   {
      // Check if index is valid
      if (sn >= 0 && sn < m_numStrings)
      {
         m_strings[sn] = gs; // Assign new GuitarStr object to specified index
         return true; // Return true to indicate successful string change
      }
      return false; // Return false if index is out of range
   }

   // Method to restring the Guitar object with a new array of GuitarStr objects and number of strings
   void Guitar::reString(GuitarStr strs[], int ns)
   {
      delete[] m_strings; // Deallocate memory for existing m_strings
      m_strings = new GuitarStr[ns]; // Allocate memory for new m_strings
      for (int i = 0; i < ns; ++i)
      {
         m_strings[i] = strs[i]; // Copy GuitarStr objects from input array to m_strings
      }

      m_numStrings = ns; // Set number of strings
   }

   // Method to remove all strings from the Guitar object
   void Guitar::deString()
   {
      delete[] m_strings; // Deallocate memory for m_strings
      m_strings = nullptr; // Set m_strings to nullptr
      m_numStrings = 0; // Set number of strings to 0
   }

   // Method to check if the Guitar object has strings
   bool Guitar::strung() const
   {
      return m_numStrings > 0; // Return true if there are strings, false otherwise
   }

   // Method to check if there is a string with a specific gauge in the Guitar object
   bool Guitar::matchGauge(double ga) const
   {
      for (int i = 0; i < m_numStrings; ++i)
      {
         if (m_strings[i].gauge() == ga) // Check if gauge matches
         {
            return true; // Return true if match found
         }
      }
      return false; // Return false if no match found
   }

   // Method to display information about the Guitar object
   std::ostream &Guitar::display(std::ostream &os) const
   {
      if (!strung()) // Check if Guitar is empty
      {
         os << "***Empty Guitar***" << endl; // Display message for empty Guitar
      }
      else
      {
         os << "Guitar Model: " << m_model << endl; // Display Guitar model
         os << "Strings: " << m_numStrings << endl; // Display number of strings
         for (int i = 0; i < m_numStrings; ++i)
         {
            os << "#" << i + 1 << "" << std::setw(MAT_LEN) << m_strings[i].material() << " | " << std::fixed << std::setprecision(1) << m_strings[i].gauge() << endl;
            // Display each string's material and gauge
         }
      }
      return os; // Return output stream
   }
}


/*
NAME - paras singh
STUDENT ID# 165-114-232
EMAIL - psingh721@myseneca.ca
DATE - 15-FEB-2024

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*/
