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

void insertionSort(std::vector<int> &x, int C) {
    int max = x.size();
    for (int i = 1; i < max; i++) {
        int currentI = x[i];
        int j = i - 1;
        int currentJ = x[j];
        while ((j >= 0) && (currentJ > currentI)) {
            x[j + 1] = x[j];
            currentJ = x[j];
            j--;
        } 
        x[j + 1] = currentI;
    } 
}

void permutate(std::vector<int> &main, int C) {
    do {
        std::vector<int> x = main;
        std::cout << "Initial" << std::endl;
        printVec(x);
        insertionSort(x,0);
        std::cout << "Sorted" << std::endl;
        printVec(x);
        
    } while(std::next_permutation(main.begin(),main.end()));
}

int main () {
    std::vector<int> x = {1,2,3}; 
    permutate(x,0);
    return 0;
}
