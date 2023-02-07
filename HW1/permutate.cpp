#include <iostream> 
#include <algorithm>
#include <functional>
#include <numeric>
#include <type_traits>
#include <vector>

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

std::vector<int> ret (int x) {
    std::vector<int> a;
    for (int i = 1; i <= x; i++) {
        a.push_back(i);
    }

    return a;
}

// Main function that does permuation of given vector 
void permutate(int n) {
    // Creates vector of [1,2,...,n]
    std::vector<int> main;
    for (int i = 1; i <= n; i++) {
        main.push_back(i);
    }
    printVec(main);
    long totalC = 0;
    long factorial = std::accumulate(main.begin(),main.end(), 1, std::multiplies<double>());
    double out;

    int Case = 0;
    int best = main.size() - 1;
    int worst = 0;

    do {
        std::vector<int> x = main;
        Case = insertionSort(x);
        
        if (Case > worst) {
            worst = Case;
        }

        totalC += Case;

    } while(std::next_permutation(main.begin(),main.end()));

    out = (double) totalC / factorial;

    std::cout << "Best:  " << best << std::endl;
    std::cout << "Worst: " << worst << std::endl;
    std::cout << "Avg:   " << out << std::endl;
}

int main (int argc, char** argv ) {
    permutate(8);

    return 0;
}
