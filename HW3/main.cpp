#include <iostream>
#include "mergesort.hpp"

int main() {
    std::vector<int> x = {8,1,5,3,4,7,6,2};
    division(x,0,x.size() - 1);
    std::cout << "Sorted" << std::endl;
    printArray(x);
    
    return 0;
}
