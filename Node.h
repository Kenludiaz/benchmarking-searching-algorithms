class Node {
    private:
    int value;
    int col;
    int row;
    Node* next;

    Node(int value, int row, int col);
    bool areNull(Node* other);
    bool isBehind(Node* other);
    bool isTied(Node* other);

    friend class Matrix;
};