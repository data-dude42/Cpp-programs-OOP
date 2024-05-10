/*
* name - paras singh
* student_id - 165114232
* email - psingh721@myseneca.ca
*/
// MatchPair.h
#ifndef SDDS_MATCHPAIR_H
#define SDDS_MATCHPAIR_H

namespace seneca {

    // Template struct for Pair
    template<typename T, typename U>
    struct Pair {
        T first;
        U second;
    };

    // Function template to add a Pair element to a dynamic array of Pairs
    template<typename T, typename U>
    void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size) {
        Pair<T, U>* temp = new Pair<T, U>[size + 1];
        for (int k = 0; pArray && k < size; k++) {
            temp[k] = pArray[k];
        }
        temp[size].first = first;
        temp[size].second = second;
        delete[] pArray;
        pArray = temp;
        size++;
    }

    // Function template to find pairs of element matches in two arrays
    template<typename T, typename U>
    Pair<T, U>* matches(const T arr1[], const U arr2[], int size1, int size2, int& matchedSize) {
        Pair<T, U>* pt = nullptr;
        matchedSize = 0;
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                if (arr1[i] == arr2[j]) {
                    addDynamicPairElement(pt, arr1[i], arr2[j], matchedSize);
                }
            }
        }
        return pt;
    }

    // Function template for releasing dynamic memory
    template<typename T>
    void releaseMem(T*& array) {
        if (array != nullptr) {
            delete[] array;
            array = nullptr;
        }
    }

} // namespace seneca

#endif // SDDS_MATCHPAIR_H
