#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->first = nullptr;
}

void Matrix::read(std::string fileName) {
    std::ifstream file;
    file.open(fileName);

    int value = 0;
    Node *temp = nullptr;

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
                    temp->previous = temp;
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
Matrix Matrix::add(Matrix& other) {
    if(!this->canBeAdded(other)) {
        std::cout << "[INVALID] These matrixes can not be added." << std::endl;
        std::exit(1);
    }
    //A copy is taken from the first matrix because every value
    //in the resulting matrix will be equivalent until the second
    //matrix has been iterated upon.
    Matrix* result = new Matrix(this->rows, this->cols);
    this->deepCopy(*(result));

    Node* resultIterator = result->first;
    Node* currentIterator = other.first;
    while(currentIterator) {
        if (!resultIterator) {
            // When the first Matrix has no more nodes
            // Then you will alwaysneed to
            // add the remaining Nodes
            // From the second Matrix
            this->pushBack(resultIterator, currentIterator);
            this->next(currentIterator);
            this->next(resultIterator);

        } else if (currentIterator->isBehind(resultIterator)) {
            Node* newNode = new Node(currentIterator->value, 
                                     currentIterator->row,
                                     currentIterator->col);
            if (result->isHead(resultIterator)) {
                Node* temp = resultIterator;
                result->first = newNode;
                newNode->next = temp;
                temp->previous = newNode;
            } else {
                Node* temp = resultIterator;
                resultIterator->previous->next = newNode;
                newNode->previous = resultIterator->previous;
                resultIterator->previous = newNode;
                newNode->next = resultIterator;
            }
            currentIterator = currentIterator->next;
        } else if (currentIterator->isTied(resultIterator)) {
            resultIterator->value += currentIterator->value;
            resultIterator = resultIterator->next;
            currentIterator = currentIterator->next;
        } else if (resultIterator->isBehind(currentIterator)) {
            resultIterator = resultIterator->next;
        }
        result->print();
        std::cout << "========================================" << std::endl;
    }

    return (*result);
}


bool Matrix::canBeAdded(Matrix& other){
    if (this->isEmpty() || other.isEmpty()) {
        std::cout << "[INVALID] One of these matrixes is empty." << std::endl;
        return false;
    } else if(this->rows == other.rows && this->cols == other.cols) {
        return true;
    } else {
        return false;
    }
}
void Matrix::deepCopy(Matrix& result) {
    Node* resultItr = nullptr;
    Node* currentItr = this->first;
    bool firstIteration = true;

    while (currentItr) {
        Node* newNode = new Node(currentItr->value, 
                                 currentItr->row, 
                                 currentItr->col);

        if (firstIteration) {
            result.first = newNode;
            resultItr = newNode;
            firstIteration = false;
        } else {
            resultItr->next = newNode;
            resultItr = resultItr->next;
        }

        currentItr = currentItr->next;
    }
}


bool Matrix::canBeMultiplied(Matrix& other){
    if (this->isEmpty() || other.isEmpty()) {
        std::cout << "[INVALID] One of these matrixes is empty." << std::endl;
        return false;
    } else if (this->cols == other.rows){
        return true;
    } else {
        return false;
    }
}
void Matrix::next(Node* iterator) {
    iterator = iterator->next;
}
bool Matrix::isHead(Node* iterator) {
    if (iterator == this->first) {
        return true;
    } 
    return false;
}
void Matrix::pushBack(Node* thisIterator, Node* otherIterator) {
    // Assertion thisIterator = NULL
    Node* newNode = new Node(otherIterator->value, 
                                otherIterator->row,
                                otherIterator->col);
    Node* previous = thisIterator->previous;
    previous->insertAhead(newNode);
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