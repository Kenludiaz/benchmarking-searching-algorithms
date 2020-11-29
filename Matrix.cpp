#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
}

void Matrix::read(std::string fileName) {
    std::ifstream file;
    file.open(fileName);

    int value = 0;
    Node *temp = nullptr;
    this->first = nullptr;

    for(int i =0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            file >> value;
            if(value != 0){
                Node *node = new Node(value, i, j);
                if(this->isEmpty()){
                    this->first = node;
                    temp = node;
                }
                else{
                    temp->next = node;
                    temp = temp->next;
                }
            }
        }
    }
    file.close();
}

bool Matrix::isEmpty() {
    if (!this->first) {
        return true;
    }
    return false;
}

void Matrix::print() {
    if (this->isEmpty()) {
        std::cout << "[INVALID] This matrix is empty." << std::endl;
        return;
    }
    Node *temp = this->first;
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            if(temp->row == i && temp->col == j){
                std::cout << temp->value << " ";
                if(temp->next != nullptr){
                    temp = temp->next;
                }
            }
            else{
                std::cout << "0" << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool Matrix::canBeAdded(Matrix& other){
    if (this->rows == other.rows && this->cols == other.cols){
        return true;
    }
    return false;
}

bool Matrix::canBeMultiplied(Matrix& other){
    if (this->cols == other.rows){
        return true;
    }
    return false;
}

Matrix::~Matrix() {
    this->destroyNodes();
}

void Matrix::destroyNodes() {
    Node* iterator = this->first;
    int i =1;
    while (iterator) {
        Node* next = iterator->next;
        delete iterator;
        iterator = next;
        if (iterator == nullptr) {
            break;
        }
    }
}