#include <iostream> 
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

// Printing function for the vector
void printVec(std::vector<int> &x) {
    for (auto i : x) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Insertion Sort
void insertionSort(std::vector<int> &x, int &C) {
    int max = x.size();
    for (int i = 1; i < max; i++) {
        int key = x[i];
        int j = i - 1;

        C++;
        while ((j >= 0) && (x[j] > key)) {
            x[j + 1] = x[j];
            j--;
            C++;
        }
        x[j + 1] = key; 
    } 
}

// Main function that does permuation of given vector 
double permutate(std::vector<int> &main) {
    double totalC = 0;
    double factorial = std::accumulate(main.begin(),main.end(), 1, std::multiplies<double>());
    double out;

    do {
        std::vector<int> x = main;
        int Ci = 0;
        insertionSort(x,Ci);
        totalC += Ci;
    } while(std::next_permutation(main.begin(),main.end()));

    out = totalC / factorial;

    return out;
}

int main () {
    std::vector<int> x = {1,2,3,4,5,6,7,8}; 
    double out = permutate(x);

    std::cout << "Average Case for Vector: ";
    printVec(x);
    std::cout << out << std::endl;

    return 0;
}
