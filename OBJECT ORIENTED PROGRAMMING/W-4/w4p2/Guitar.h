/***********************************************************************
// OOP244 Workshop #4 p2: tester program
// File  main.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca
{

   const int MAT_LEN = 10;

   class GuitarStr
   {
      char m_material[MAT_LEN]{};
      double m_gauge{};

   public:
      const char *material() const;
      double gauge() const;
      GuitarStr();
      GuitarStr(const char *ma, double ga);
   };

   class Guitar
   {
      GuitarStr *m_strings; // a dynamic array of GuitarStr(m_strings)
      int m_numStrings;     // the number of GuitarStr in the array (m_numStrings)
      char m_model[15];     // a model name for the Guitar with a maximum length of 15 characters(m_model)

   public:

      // constructors/destructors
      Guitar(const char *mod = "Stratocaster");
      Guitar(GuitarStr strs[], int ns, const char *mod);
      ~Guitar();

      // modifiers
      bool changeString(const GuitarStr &gs, int sn);
      void reString(GuitarStr strs[], int ns);
      void deString();

      // queries
      bool strung() const;
      bool matchGauge(double ga) const;
      std::ostream& display(std::ostream& os = std::cout) const;
   };

}

#endif
