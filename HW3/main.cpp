#include "mergesort.hpp"

void driver(std::vector<int> &x) {
    std::cout << "Unsorted" << std::endl;
    printArray(x);
    std::cout << "Sorting" << std::endl;
    division(x,0,x.size() - 1);
    std::cout << "Sorted" << std::endl;
    printArray(x);
 
}
int main() {
    std::vector<int> x = {8,1,5,3,4,7,6,2};
    driver(x);
    return 0;
}
