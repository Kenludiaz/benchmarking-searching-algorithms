#include "Matrix.h"

int main() {
    Matrix testAdd1(3, 4);
    testAdd1.read("addition.txt");
    Matrix testAdd2(3, 4);
    testAdd2.read("addition2.txt");
    testAdd1.add(testAdd2).print();

    Matrix testMult1(2, 3);
    testMult1.read("multiplication1.txt");
    Matrix testMult2(3, 2);
    testMult2.read("multiplication2.txt");
    testMult1.multiply(testMult2).print();

}