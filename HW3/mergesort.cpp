#include "mergesort.hpp"

void printArray(std::vector<int> &vec) {
    std::cout << "[ ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void division(std::vector<int> A, int min, int max) {
    if (min < max) {
        int middle = min + (max - min) / 2; 
        // Divide the min side
        division(A, min, middle);

        // Divide the max side
        division(A, middle + 1, max);

        // Merge the arrays together
        mergeMe(A, min, middle, max);
        printArray(A);
    }
}

void mergeMe(std::vector<int> &A, int left, int middle, int right) {
    std::vector<int> LVec;
    std::vector<int> RVec;
    
    int lMax = middle - left + 1;
    int rMax = right + middle;

    // Creating left side array
    for (int i = 0; i < lMax; i++) {
        LVec.push_back(A[left + i]);
    }

    // Creating right side array
    for (int i = 0; i < rMax; i++) {
        RVec.push_back(A[middle + 1 + i]);
    }

    int i = 0;
    int j = 0;
    int k = left;
    
    while ((i < lMax) && (j < rMax)) {
        if (LVec[i] <= RVec[j]) {
            A[k] = LVec[i];
            i++;
        }
        else {
            A[k] = RVec[j];
            j++;
        }
        k++;
    }
    
    while (i < lMax) {
        A[k] = LVec[i];
        i++;
        k++;
    }

    while (j < rMax) {
        A[k] = LVec[j];
        j++;
        k++;
    }
} 


