#include <iostream> 
#include <algorithm>
#include <functional>
#include <numeric>
#include <type_traits>
#include <vector>
#include <random>
#include <iterator>
#include "sample.hpp"

// Printing function for the vector
void printVec(std::vector<int> &x) {
    int max = x.size();
    std::cout << "[ ";
    for (int i = 0; i < max; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// Insertion Sort
int insertionSort(std::vector<int> &x) {
    int C = 0;
    int max = x.size();
    for (int i = 1; i < max; i++) {
        int key = x[i];
        int j = i - 1;

        while (j >= 0) { 
            C++;
            if (x[j] > key) { 
                x[j + 1] = x[j];
                j--;
            }
            else {
                break;
            }
        }
        x[j + 1] = key; 
    } 
    return C;
}
float coincidence(std::vector<int> &A) {
    float coin = 0;
    int max = A.size();
    for (int i = 0; i < max; i++) {
        int j = i + 1;
        if (j == A[i]) {
            coin += 1;
        }
    } 
    return coin;
}

// Main function that does permuation of given vector 
void permutate(int n) {
    // Creates vector of [1,2,...,n]
    std::vector<int> main;
    for (int i = 1; i <= n; i++) {
        main.push_back(i);
    }

    int iters = 0;
    int tests = 100;
    float Case = 0;
    long totalC = 0;

    std::random_device rd;
    std::mt19937 rng(rd());

    std::vector<float> Cx;
        
    while (iters < tests) {
        std::shuffle(main.begin(),main.end(),rng);
        std::vector<int> x = main;
        Case = coincidence(x);
        Cx.push_back(Case);
        totalC += Case;

        iters++; 
    } 

    float mean = sampleMean(tests,Cx);
    float variance = sampleVariance(tests,mean,Cx);
    
    std::cout << "    Sample Mean = " << mean << std::endl;
    //std::cout << "Sample Variance = " << variance << std::endl;
}

int main (int argc, char** argv ) {
    permutate(20);

    return 0;
}
