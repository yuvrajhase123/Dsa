#include <iostream>
#include <string>
#include <cctype> // For isdigit and isalpha functions
using namespace std;

// Node structure for the linked list (used for stack implementation)
struct Node {
    char data;
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
    void push(char c) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    // Pop function to remove top element from stack
    char pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return '\0'; // Return a null character if stack is empty
        }
        char data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    // Peek function to return the top element of the stack
    char peek() {
        if (top == nullptr) {
            return '\0';
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to get precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0; // For '(' and other non-operator characters
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(c)) {
            postfix += c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(') {
            s.push(c);
        }
        // If the character is ')', pop until '(' is found
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Pop the '(' from the stack
        }
        // If the character is an operator
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    // Pop any remaining operators from the stack
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
