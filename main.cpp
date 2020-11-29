#include "Matrix.h"

int main() {
    Matrix test(3, 4);
    test.read("sample.txt");
    

    std::cout << "This matrix is empty: " << test.isEmpty()
    << std::endl;

}