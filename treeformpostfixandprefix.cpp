#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Tree Node Structure
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char c) {
        data = c;
        left = right = nullptr;
    }
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 1. Construct Expression Tree from Postfix Expression
Node* constructPostfixTree(string postfix) {
    stack<Node*> stk;
    for (char& c : postfix) {
        if (!isOperator(c)) {
            stk.push(new Node(c));  // Operand: create a node and push to stack
        } else {
            Node* node = new Node(c);  // Operator: create a node
            node->right = stk.top(); stk.pop();
            node->left = stk.top(); stk.pop();
            stk.push(node);  // Push the node back to stack
        }
    }
    return stk.top();  // The root of the tree
}

// 2. Construct Expression Tree from Prefix Expression
Node* constructPrefixTree(string prefix) {
    stack<Node*> stk;
    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; --i) {
        char c = prefix[i];
        if (!isOperator(c)) {
            stk.push(new Node(c));  // Operand: create a node and push to stack
        } else {
            Node* node = new Node(c);  // Operator: create a node
            node->left = stk.top(); stk.pop();
            node->right = stk.top(); stk.pop();
            stk.push(node);  // Push the node back to stack
        }
    }
    return stk.top();  // The root of the tree
}

// 3. Recursive Pre-order Traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";  // Visit root
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

// 4. Recursive In-order Traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);        // Traverse left subtree
    cout << root->data << " ";  // Visit root
    inorder(root->right);       // Traverse right subtree
}

// 5. Recursive Post-order Traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);      // Traverse left subtree
    postorder(root->right);     // Traverse right subtree
    cout << root->data << " ";  // Visit root
}

int main() {
    string postfix, prefix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    // Construct Expression Tree from Postfix
    Node* rootPostfix = constructPostfixTree(postfix);

    // Construct Expression Tree from Prefix
    Node* rootPrefix = constructPrefixTree(prefix);

    cout << "\nPostfix Expression Tree Traversals:\n";
    cout << "Pre-order: "; preorder(rootPostfix); cout << endl;
    cout << "In-order: "; inorder(rootPostfix); cout << endl;
    cout << "Post-order: "; postorder(rootPostfix); cout << endl;

    cout << "\nPrefix Expression Tree Traversals:\n";
    cout << "Pre-order: "; preorder(rootPrefix); cout << endl;
    cout << "In-order: "; inorder(rootPrefix); cout << endl;
    cout << "Post-order: "; postorder(rootPrefix); cout << endl;

    return 0;
}
