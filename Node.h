class Node {
    private:
    int value;
    int col;
    int row;
    Node* next;

    friend class Matrix;
};