Skip to content
Search or jump to…

Pull requests
Issues
Marketplace
Explore

@jbinwu39
Kenludiaz
/
sparse-matricies-linked-lists
1
0
0
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
sparse-matricies-linked-lists/Matrix.cpp
@Kenludiaz
Kenludiaz Adds statement to create nodes in result matrix
Latest commit 3ca8291 5 hours ago
 History
 2 contributors
@Kenludiaz@jbinwu39
157 lines (138 sloc)  4.08 KB

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
<<<<<<< Updated upstream
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
            Node* newNode = new Node(currentIterator->value, 
                                     currentIterator->row,
                                     currentIterator->col);
            Node* previous = resultIterator->previous;
            previous->next = newNode;
            newNode->previous = previous;
            resultIterator = newNode;
            currentIterator = currentIterator->next;

        } else if (currentIterator->isBehind(resultIterator)) {
            Node* newNode = new Node(currentIterator->value, 
                                     currentIterator->row,
                                     currentIterator->col);
            if (resultIterator == result->first) {
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

=======
Matrix Matrix::multiply(Matrix& multiply){
    if(!this->canBeMultiplied(multiply)){
        std::cout << "[INVALID] These matrixes can not be multiply." << std::endl;
        std::exit(1);
    }
    int counter = 0;
    for(int i = 0; i < this->rows; i++){
        node *temp1 = this->first;
        node *temp2 = multiply.first;
        for(int j = 0; j <multiply.rows; j++){
            int value = 0;
            while(temp1->next != nullptr || temp1->next != nullptr){
                if(temp->rows = i && multiply.cols = j){
                    value += this->value * multiply.value;
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                else{
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
            }
            Node* newNode = new(value, i, j);
            node *temp1 = this->first;
            node *temp2 = multiply.first;
        }
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
        if (resultIterator == nullptr) {
            Node* newNode = new Node(currentIterator->value,
                                     currentIterator->row,
                                     currentIterator->col);
            Node* previous = resultIterator->previous;
            previous->next = newNode;
            newNode->previous = previous;
            resultIterator = newNode;
            currentIterator = currentIterator->next;

        } else if (currentIterator->isBehind(resultIterator)) {

        } else if (currentIterator->isTied())
    }

>>>>>>> Stashed changes
    return (*result);
}


<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======


>>>>>>> Stashed changes
void Matrix::deepCopy(Matrix& result) {
    Node* resultItr = nullptr;
    Node* currentItr = this->first;
    bool firstIteration = true;

    while (currentItr) {
<<<<<<< Updated upstream
        Node* newNode = new Node(currentItr->value, 
                                 currentItr->row, 
=======
        Node* newNode = new Node(currentItr->value,
                                 currentItr->row,
>>>>>>> Stashed changes
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