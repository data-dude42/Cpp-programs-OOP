/***********************************************************************
// OOP244 Workshop #4 p2
//
// File	Fridge.h
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <iomanip>
#include <string>
#include <cstring>
#include <iostream>

namespace seneca
{

   const int NAME_LEN = 20, FRIDGE_CAP = 3;

   class Food
   {
      char m_name[NAME_LEN]{};
      int m_weight{};

   public:
      const char *name() const;
      int weight() const;
      Food();
      Food(const char *nm, int wei);
   };

   class Fridge
   {

      Food m_foods[FRIDGE_CAP];
      int m_numFoods;
      char *m_model;

   public:
      // Constructor
      Fridge();

      // Constructor with three parameters
      Fridge(Food farr[], int nf, const char *mod = "Ice Age");

      ~Fridge();

      // Attempt to add food items
      bool addFood(const Food &f);

      // Modify the model name.
      void changeModel(const char *m);

      // Returns if fridge is full or not
      bool fullFridge() const;

      // Searches the fridge for the food in the parameter
      bool findFood(const char *f) const;

      std::ostream &display(std::ostream &os = std::cout) const;
   };
}

#endif
