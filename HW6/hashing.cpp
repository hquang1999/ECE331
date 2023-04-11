#include <iostream>
#include <vector>
#include <random>

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

void beginHashing(std::vector<int> &hashMe,int elemHS) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> num(1,1000);
    int max = elemHS;

    for (int i = 0; i < max; i++) {
        int randOut = num(rng);

    } 
}

int returnIndex(std::vector<int> &hashMe, int x) {
    return 0;
}

void runner(std::vector<int> &hashMe,int elemHS) {
    beginHashing(hashMe, elemHS);
    printHash(hashMe);
}

int main() {
    int elemHS = 15;
    int maxSZ = 23;
    std::vector<int> hashMe(maxSZ,-1);
    runner(hashMe, 15);
}
