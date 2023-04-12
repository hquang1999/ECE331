#include <iostream>
#include <vector>
#include <random>
#include <getopt.h>

int elemI;

void printHash(std::vector<int> &hashMe) {
    int max = hashMe.size();
    int value = 0;
    std::cout << "[ ";
    for (int i = 0; i < max; i++) {
        value = hashMe[i];
        if (value == -1) {
            std::cout << " x "; 
        }
        else {
            std::cout << " " << value << " ";
        }
    }
    std::cout << "]" << std::endl; 
}

int placeIndex(std::vector<int> &hashMe, int randX, int m) {
    int max = hashMe.size();
    int  index = 0;
    for (int i = 0; i < max; i++) {
        index = (randX + (i * (1 + (randX % (m - 1))))) % m;
        if (hashMe[index] == -1) {
            hashMe[index] = randX;
            elemI = i;
            break;
        }
    }
    return index;
}

void beginHashing(std::vector<int> &hashMe, int m, int n) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> num(1,1000);
    int count = 1;
    for (int i = 0; i < n; i++) {
        int randOut = num(rng);
        int index = placeIndex(hashMe,randOut,m);
        std::cout << count << ". " << "h(" << randOut << "," 
            << elemI << ") = " << index << std::endl;
        count++;
    } 
}

void runner(int m, int n) {
    std::vector<int> hashMe(m,-1);
    if (n <= m) {
        std::cout << "H(k,i) Result:" << std::endl;
        beginHashing(hashMe, m, n);
        std::cout << std::endl;
        std::cout << "Output Array:" << std::endl;
    
        printHash(hashMe);
        
    }
    else {
        std::cout << "ERROR: random array size > storage array" << std::endl;
    }
}

int main(int argc, char** argv) {
    int m = 0;
    int n = 0;
    int opt = 0;
    while ((opt = getopt(argc,argv,"M:N:")) != -1) {
        switch(opt) {
            case 'M':
                m = atoi(optarg);
                break;
            case 'N':
                n = atoi(optarg);
                break;
            default:
                std::cout << "No Input!" << std::endl;        
        }    
    }

    runner(m, n);
    return 0;
}
