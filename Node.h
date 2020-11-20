class Node {
    private:
    int value;
    int col;
    int row;
    Node* next;

    Node::Node(int value, int row, int col);

    friend class Matrix;
};