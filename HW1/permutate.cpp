#include <iostream> 
#include <algorithm>
#include <vector>

// Printing function for the vector
void printVec(std::vector<int> &x) {
    for (auto i : x) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Insertion Sort
void insertionSort(std::vector<int> &x, int C) {
    int max = x.size();
    for (int i = 1; i < max; i++) {
        int key = x[i];
        int j = i - 1;

        while ((j >= 0) && (x[j] > key)) {
            x[j + 1] = x[j];
            j--;
        }
        x[j + 1] = key; 
    } 
}

// Main function that does permuation of given vector 
void permutate(std::vector<int> &main, int C) {
    do {
        std::vector<int> x = main;
        std::cout << "Initial" << std::endl;
        printVec(x);
        insertionSort(x,0);
        std::cout << "Sorted" << std::endl;
        printVec(x);
        std::cout << std::endl;
    } while(std::next_permutation(main.begin(),main.end()));
}

int main () {
    std::vector<int> x = {1,2,3,4}; 
    permutate(x,0);

    return 0;
}
