#include <iostream>
using namespace std;

// Binary Search Tree (BST) Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST class
class BST {
private:
    Node* root;

    // Helper function to insert a new node
    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
        return root;
    }

    // Helper function for searching a node in the tree
    bool searchNode(Node* root, int value) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == value) {
            return true;
        }
        if (value < root->data) {
            return searchNode(root->left, value);
        } else {
            return searchNode(root->right, value);
        }
    }

    // Helper function to calculate the depth (height) of the tree
    int depth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // Helper function to display leaf nodes
    void displayLeafNodes(Node* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->data << " ";
        }
        displayLeafNodes(root->left);
        displayLeafNodes(root->right);
    }

public:
    // Constructor to initialize an empty tree
    BST() {
        root = nullptr;
    }

    // Insert function
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Search function
    bool search(int value) {
        return searchNode(root, value);
    }

    // Display depth (height) of the tree
    int displayDepth() {
        return depth(root);
    }

    // Display leaf nodes of the tree
    void displayLeaf() {
        cout << "Leaf nodes: ";
        displayLeafNodes(root);
        cout << endl;
    }

    // Function to display the tree (In-order traversal)
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void display() {
        cout << "In-order Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, value;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Display Depth\n4. Display Leaf Nodes\n5. Display Tree (In-order)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value)) {
                cout << value << " found in the tree.\n";
            } else {
                cout << value << " not found in the tree.\n";
            }
            break;
        case 3:
            cout << "Depth of tree: " << tree.displayDepth() << endl;
            break;
        case 4:
            tree.displayLeaf();
            break;
        case 5:
            tree.display();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
