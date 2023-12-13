#include "bst.h"
#include <iostream>

int main() {
    BST bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Print inorder traversal
    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();
    std::cout << std::endl;

    // Print preorder traversal
    std::cout << "Preorder Traversal: ";
    bst.preorderTraversal();
    std::cout << std::endl;

    // Print postorder traversal
    std::cout << "Postorder Traversal: ";
    bst.postorderTraversal();
    std::cout << std::endl;

    // Search for a value in the BST
    int searchValue = 40;
    Node* searchResult = bst.search(searchValue);
    if (searchResult) {
        std::cout << "Found " << searchValue << " in the BST." << std::endl;
    } else {
        std::cout << searchValue << " not found in the BST." << std::endl;
    }

    // Get minimum and maximum values in the BST
    Node* minNode = bst.getMin();
    Node* maxNode = bst.getMax();
    std::cout << "Minimum value in the BST: " << minNode->key << std::endl;
    std::cout << "Maximum value in the BST: " << maxNode->key << std::endl;

    // Get height of the BST
    int height = bst.getHeight();
    std::cout << "Height of the BST: " << height << std::endl;

    // Find predecessor and successor of a node
    Node* nodeToFind = bst.search(30);
    Node* predecessorNode = bst.predecessor(nodeToFind);
    Node* successorNode = bst.successor(nodeToFind);

    if (predecessorNode) {
        std::cout << "Predecessor of " << nodeToFind->key << ": " << predecessorNode->key << std::endl;
    } else {
        std::cout << "No predecessor for " << nodeToFind->key << "." << std::endl;
    }

    if (successorNode) {
        std::cout << "Successor of " << nodeToFind->key << ": " << successorNode->key << std::endl;
    } else {
        std::cout << "No successor for " << nodeToFind->key << "." << std::endl;
    }

    return 0;
}
