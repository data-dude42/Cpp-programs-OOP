/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
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
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Fridge.h" // Include the header file where the class declarations are defined
using namespace std;

namespace seneca
{

    // Implementation of Food class member functions
    const char *Food::name() const
    {
        return m_name;
    }

    int Food::weight() const
    {
        return m_weight;
    }

    Food::Food() {} // Default constructor

    // Parameterized constructor to initialize name and weight
    Food::Food(const char *nm, int wei)
    {
        strncpy(m_name, nm, NAME_LEN);
        m_weight = wei;
    }

    // Implementation of Fridge class member functions

    // Default constructor: sets the data members to an empty state
    Fridge::Fridge()
    {
        m_numFoods = 0;
        m_model = nullptr;
    }

    // 3-argument constructor to initialize data members based on provided parameters
    Fridge::Fridge(Food farr[], int nf, const char *mod)
    {
        *this = Fridge(); // Invoke default constructor to set initial state

        // Check if nf is positive and mod is not null or empty
        if (nf > 0 && (mod != nullptr && *mod != '\0'))
        {
            m_numFoods = nf;
            m_model = new char[strlen(mod) + 1];
            strcpy(m_model, mod);

            // Copy food items from the array to the fridge
            for (int i = 0; (i < nf && i < FRIDGE_CAP); i++)
            {
                m_foods[i] = farr[i];
            }
        }
    }

    // Destructor: deallocates memory
    Fridge::~Fridge()
    {
        delete[] m_model; // Deallocate memory for model name
        m_model = nullptr;
    }

    // Attempt to add food items to the fridge
    bool Fridge::addFood(const Food &f)
    {
        if (m_numFoods < FRIDGE_CAP) // Check if fridge has capacity
        {
            m_foods[m_numFoods] = f; // Add food item to array
            m_numFoods++;            // Increment count of food items
            return true;
        }
        else
        {
            return false; // Fridge is full
        }
    }

    // Modify the model name of the fridge
    void Fridge::changeModel(const char *m)
    {
        if (m != nullptr && *m != '\0') // Check if provided model name is not null or empty
        {
            delete[] m_model;                  // Deallocate previously allocated memory
            m_model = new char[strlen(m) + 1]; // Allocate new memory for model name
            strcpy(m_model, m);                // Copy model name
        }
    }

    // Check if fridge is full
    bool Fridge::fullFridge() const
    {
        return (m_numFoods == FRIDGE_CAP); // Return true if fridge is full
    }

    // Search for a food item in the fridge
    bool Fridge::findFood(const char *f) const
    {
        if (f != nullptr && *f != '\0') // Check if provided food name is not null or empty
        {
            for (int i = 0; i < m_numFoods; i++) // Loop through food items in the fridge
            {
                if (strcmp(m_foods[i].name(), f) == 0) // Compare food names
                {
                    return true; // Food found
                }
            }
        }
        return false; // Food not found
    }

    // Display information about the fridge
    std::ostream &Fridge::display(std::ostream &os) const
    {
        if (m_model == nullptr || m_model[0] == '\0') // Check if model name is empty
        {
            return os; // Return if model name is empty
        }
        else
        {
            os << "Fridge Model: " << m_model << endl
               << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl
               << "List of Foods" << endl;

            // Display list of foods in the fridge
            for (int i = 0; i < m_numFoods; i++)
            {
                os << setw(NAME_LEN) << m_foods[i].name() << " | " << m_foods[i].weight() << endl;
            }
        }
        return os;
    }
}



// name- paras singh , studentid-165114232, email- psingh721@myseneca.ca, date- 10-FEB-2024
