#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>

class Matrix {
    private:
        Node* first;
        Node* iterator;
        int rows;
        int cols;
    

        bool canBeAdded(Matrix& other);
        bool canBeMultiplied(Matrix& other);
        void destroyNodes();
        void deepCopy(Matrix& result);
        void next(Node* iterator);
        bool isHead(Node* iterator);
        void pushBack(Node* thisIterator, Node* newNode);
        void pushFront(Node* thisIterator, Node* otherIterator, Node* newNode);
    
    public:
        Matrix(int rows, int cols);
        ~Matrix();

        void read(std::string fileName);
        bool isEmpty();
        void print();
        Matrix add(Matrix& other);
        Matrix multiply(Matrix& multiply);
};