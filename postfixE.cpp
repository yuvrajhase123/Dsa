//Implement stack as an abstract data type using singly linked list and use this ADT for evaluation of
//postfix expression.
#include <iostream>
#include <cctype> // For isdigit function
#include <stack>  // For the standard stack class (optional, we implement our own)

using namespace std;

// Node structure for the linked list (used for stack implementation)
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr; // Initialize stack as empty
    }

    // Push function to add element to stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop function to remove top element from stack
    int pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return -1; // Return an invalid value
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek function to return the top element of the stack
    int peek() {
        if (top == nullptr) {
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    Stack s;

    for (char c : postfix) {
        // If the character is a digit, push it to the stack
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        }
        // If the character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = s.pop();
            int operand1 = s.pop();
            int result = 0;

            switch (c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }

            // Push the result of the operation back to the stack
            s.push(result);
        }
    }

    // The final result is the only element left in the stack
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
