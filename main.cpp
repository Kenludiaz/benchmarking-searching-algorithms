#include "Matrix.h"

int main() {
    Matrix test1(3, 4);
    test1.read("addition.txt");
    Matrix test2(3, 4);
    test2.read("addition2.txt");


    // std::cout << "This matrix is empty: " << test.isEmpty()
    // << std::endl;
    // std::cout << "This matrix can be added: " << test1.canBeAdded(test2)
    // << std::endl;
    // std::cout << "This matrix can be multipied: " << test1.canBeMultiplied(test2)
    // << std::endl;
    test1.add(test2).print();
    // test1.multiply(test2);

}