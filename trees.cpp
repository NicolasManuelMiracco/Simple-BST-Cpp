#include <iostream>

using namespace std;

// Definition of the TreeNode class
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

// Definition of the BinarySearchTree class
class BinarySearchTree {
public:
    TreeNode* root;

    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Insert value into the tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Function to insert value recursively
    TreeNode* insertRecursive(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->value) {
            node->right = insertRecursive(node->right, value);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Function to print the tree in-order (for verification)
    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->value << " ";
            inOrder(node->right);
        }
    }
};

// Function to build the binary search tree from an array of integers
BinarySearchTree buildTreeFromIntArray(int arr[], int size) {
    BinarySearchTree bst;
    for (int i = 0; i < size; i++) {
        bst.insert(arr[i]);
    }
    return bst;
}

int main() {
    int elements[] = {15, 10, 20, 8, 12, 17, 25};
    int size = sizeof(elements) / sizeof(elements[0]);

    BinarySearchTree bst = buildTreeFromIntArray(elements, size);

    cout << "In-order traversal of the binary search tree: ";
    bst.inOrder(bst.root);
    cout << endl;

    return 0;
}
