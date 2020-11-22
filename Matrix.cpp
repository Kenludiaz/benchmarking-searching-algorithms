#include "Matrix.h"

void Matrix::read(std::string fileName, int row, int col) {
    std::ifstream file;
    file.open(fileName);
    this->rows = row;
    this->cols = col;


    int value = 0;
    Node *temp = nullptr;
    this->first = nullptr;
    for(int i =0; i < row; i++){
        for(int j = 0; j < col; j++){
            std::cout << i << " "<< j << std::endl;
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
