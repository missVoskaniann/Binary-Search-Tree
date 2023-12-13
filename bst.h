#ifndef BST_H
#define BST_H

class Node {
public:
    Node* left;
    Node* right;
    int key;

    Node(int k);
};

class BST {
public:
    BST();
    void inorderTraversal();
    void postorderTraversal();
    void preorderTraversal();

    void insert(int k);
    Node* getMin();
    Node* getMax();
    Node* search(int k);
    int getHeight();
    Node* predecessor(Node* x);
    Node* successor(Node* x);

private:
    Node* root;

    void inorderTraversal(Node* r);
    void postorderTraversal(Node* r);
    void preorderTraversal(Node* r);
    void insert(Node*& r, int k);
    Node* search(Node* n, int k);
    Node* getMin(Node* x);
    Node* getMax(Node* x);
    int getHeight(Node* x);



};
#endif // BST_H