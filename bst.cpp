#include "bst.h"

#include <iostream>
#include <algorithm>

Node::Node(int k) : left{nullptr}, right{nullptr}, key{k} {}

BST::BST() : root{nullptr} {}
void BST::inorderTraversal(Node* r) {
    if (r != nullptr) {
        inorderTraversal(r->left);
        std::cout << r->key << " ";
        inorderTraversal(r->right);
    }
}

void BST::inorderTraversal() {
    inorderTraversal(root);
}

void BST::preorderTraversal(Node* r) {
    if (r != nullptr) {
        std::cout << r->key << " ";
        preorderTraversal(r->left);
        preorderTraversal(r->right);
    }
}

void BST::preorderTraversal() {
    preorderTraversal(root);
}

void BST::postorderTraversal(Node* r) {
    if (r != nullptr) {
        postorderTraversal(r->left);
        postorderTraversal(r->right);
        std::cout << r->key << " ";
    }
}

void BST::postorderTraversal() {
    postorderTraversal(root);
}

void BST::insert(Node*& r, int k) {
    if (r == nullptr) {
        r = new Node(k);
    } else if (k < r->key) {
        insert(r->left, k);
    } else {
        insert(r->right, k);
    }
}

void BST::insert(int k) {
    insert(root, k);
}

void BST::remove(Node*& r, int k) {
    if (r == nullptr) {
        return;
    }
    if (k < r->key) {
        remove(r->left, k);
    } else if (k > r->key) {
        remove(r->right, k);
    } else {
        if (r->left == nullptr) {
            Node* tmp = r->right;
            delete r;
            r = tmp;
        } else if (r->right == nullptr) {
            Node* tmp = r->left;
            delete r;
            r = tmp;
        } else {
            Node* tmp = getMin(r->right);
            r->key = tmp->key;
            remove(r->right, tmp->key);
        }
    }
}

void BST::remove(int k) {
    remove(root, k);
}

Node* BST::search(Node* n, int k) {
    while (n != nullptr && k != n->key) {
        if (k < n->key) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
    return n;
}

Node* BST::search(int k) {
    return search(root, k);
}

Node* BST::getMin(Node* x) {
    if (!x) {
        return nullptr;
    }
    while (x->left) {
        x = x->left;
    }
    return x;
}

Node* BST::getMin() {
    return getMin(root);
}

Node* BST::getMax(Node* x) {
    if (!x) {
        return nullptr;
    }
    while (x->right) {
        x = x->right;
    }
    return x;
}

Node* BST::getMax() {
    return getMax(root);
}

int BST::getHeight(Node* x) {
    if (!x) {
        return -1;
    }
    return std::max(getHeight(x->left), getHeight(x->right)) + 1;
}

int BST::getHeight() {
    return getHeight(root);
}

Node* BST::predecessor(Node* x) {
    if (x == nullptr) {
        return nullptr;
    }
    if (x->left != nullptr) {
        return getMax(x->left);
    }
    Node* y = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (x->key > current->key) {
            y = current;
            current = current->right;
        } else if (x->key < current->key) {
            current = current->left;
        } else {
            break;
        }
    }
    return y;
}


Node* BST::successor(Node* x) {
    if (x == nullptr) {
        return nullptr;
    }
    if (x->right != nullptr) {
        return getMin(x->right);
    }
    Node* y = nullptr;
    Node* current = root;
    while (current != nullptr) {
        if (x->key < current->key) {
            y = current;
            current = current->left;
        } else if (x->key > current->key) {
            current = current->right;
        } else {
            break;
        }
    }
    return y;
}


