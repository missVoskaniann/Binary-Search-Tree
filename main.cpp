#include "bst.h"
#include <iostream>

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();
    std::cout << std::endl;

    std::cout << "Preorder Traversal: ";
    bst.preorderTraversal();
    std::cout << std::endl;

    std::cout << "Postorder Traversal: ";
    bst.postorderTraversal();
    std::cout << std::endl;

    int searchValue = 40;
    Node* searchResult = bst.search(searchValue);
    if (searchResult) {
        std::cout << "Found " << searchValue << " in the BST." << std::endl;
    } else {
        std::cout << searchValue << " not found in the BST." << std::endl;
    }

    Node* minNode = bst.getMin();
    Node* maxNode = bst.getMax();
    std::cout << "Minimum value in the BST: " << minNode->key << std::endl;
    std::cout << "Maximum value in the BST: " << maxNode->key << std::endl;

    int height = bst.getHeight();
    std::cout << "Height of the BST: " << height << std::endl;

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

    int deleteValue = 40;
    std::cout << "Deleting node with value " << deleteValue << " from the BST." << std::endl;
    bst.remove(deleteValue);

    std::cout << "Inorder Traversal after deletion: ";
    bst.inorderTraversal();
    std::cout << std::endl;

    return 0;
}
