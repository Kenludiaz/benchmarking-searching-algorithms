#include "Matrix.h"

void Matrix::read(std::string fileName) {
    std::ifstream file;
    file.open(fileName);
    
    int row = 0;
    int col = 0;
    int value = 0;
    while (value != NULL) {
        file >> value;
        if (value == 0) {
            continue;
        }
        Node node = new Node(value,)
    }
}

bool Matrix::isEmpty() {
    if (this->first == nullptr) {
        return true;
    }
    return false;
}
// void Matrix::print() {

//     while 
// }