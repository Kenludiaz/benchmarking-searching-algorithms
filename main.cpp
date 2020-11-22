#include "Matrix.h"

int main() {
    Matrix test;
    test.read("sample.txt", 3, 4);
    
    // Matrix test2;
    std::cout << "This matrix is empty: " << test.isEmpty()
    << std::endl;

}