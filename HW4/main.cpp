#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <getopt.h>

int comps = 0;
int swaps = 0;
int parts = 0;

void printArray(std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto i : vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

float SM (int sumI, int tests) {
    float ret = (float) sumI / tests;
    return ret;
}

int partition(std::vector<int> &A, int p, int r) {
    parts++;
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        comps++;
        if (A[j] <= x) {
            swaps++;
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    i++;
    int temp = A[i];
    A[i] = A[r];
    A[r] = temp;
    swaps++;

    return i;
}
 
void quicksort(std::vector<int> &A, int p, int r) {
    if (p < r) {
        int q = partition(A,p,r);
        int lessQ = q - 1;
        int greatQ = q + 1;
        quicksort(A,p,lessQ);
        quicksort(A,greatQ,r);
    }
} 

void driver(int sz) {
    std::vector<int> x;
    for (int i = 0; i < sz; i++) {
        int j = i;
        j++;
        x.push_back(j);
    }

    std::random_device rd;
    std::mt19937 rng(rd());

    int iters = 0;
    int tests = 1000;
    std::vector<int> temp;

    while (iters < tests) {
        std::shuffle(x.begin(),x.end(),rng);
        temp = x;
        quicksort(temp,0,temp.size() - 1);
        iters++;
    }

    std::cout << "C = " << SM(comps,tests) << std::endl;
    std::cout << "S = " << SM(swaps,tests) << std::endl;
    std::cout << "P = " << SM(parts,tests) << std::endl;
}

int main (int argc, char** argv) { 
    int input = 0;
    int opt = 0;

    comps = 0;  
    swaps = 0;
    parts = 0;

    while ((opt = getopt(argc,argv,"N:")) != -1) {
        switch (opt) {
            case 'N':
                input = atoi(optarg);
                driver(input);
                break;
            default:
                std::cout << "Nah" << std::endl;
                break;
        }
    }

    return 0;
}
