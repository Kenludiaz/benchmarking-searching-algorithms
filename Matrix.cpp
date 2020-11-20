#include "Matrix.h"

bool Matrix::isEmpty() {
    if (this->first == nullptr) {
        return true;
    }
    return false;
}