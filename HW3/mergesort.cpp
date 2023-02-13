#include "mergesort.hpp"

void printArray(std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void division(std::vector<int> &A, int min, int max) {
    if (min < max) {
        int middle = min + (max - min) / 2; 
        // Divide the min side
        division(A, min, middle);

        // Divide the max side
        int tm = middle + 1;
        division(A, tm, max);

        // Merge the arrays together
        mergeMe(A, min, middle, max);
        
        printArray(A);
    }
}

void mergeMe(std::vector<int> &A, int left, int middle, int right) {
    std::vector<int> LVec;
    std::vector<int> RVec;
    
    int lMax = middle - left + 1;
    int rMax = right - middle;

    // Getting the left side array
    for (int i = 0; i < lMax; i++) {
        LVec.push_back(A[left + i]);
    }

    // Getting the right side array
    for (int i = 0; i < rMax; i++) {
        RVec.push_back(A[middle + 1 + i]);
    }

    int i = 0;
    int j = 0;
    int k = left;
    
    // Begin comparisons, checking if we reach either the left or right limit
    while ((i < lMax) && (j < rMax)) {
        // If element from left side is <= right side
        if (LVec[i] <= RVec[j]) {
            // Replace them into the array
            A[k] = LVec[i];
            // Increment to the next element
            i++;
        }
        // If elements from the right side is <= left side
        else {
            // Replace them into the array
            A[k] = RVec[j];
            // Increment to the next element
            j++;
        }
        // Increment to the next element
        k++;
    }
    
    // This section is clean up for when we leave the while loop
    
    // If the right array finishes, then add back the remaining left array elements
    while (i < lMax) {
        A[k] = LVec[i];
        i++;
        k++;
    }

    // If the left array finishes, then add back the remaining right array elements
    while (j < rMax) {
        A[k] = RVec[j];
        j++;
        k++;
    }
} 


