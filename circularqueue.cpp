#include <iostream>
using namespace std;

// Node structure for the circular linked list (used for queue)
struct Node {
    int data;
    Node* next;
};

// Queue class using circular linked list
class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor to initialize an empty queue
    CircularQueue() {
        front = rear = nullptr;
    }

    // Enqueue (Insert) operation
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (front == nullptr) {
            front = rear = newNode;
            newNode->next = front; // Points to itself as it's the only element
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Points back to the front to maintain circularity
        }
        cout << value << " enqueued to queue\n";
    }

    // Dequeue (Delete) operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        if (front == rear) {
            // Only one element in the queue
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; // Rear points to new front to maintain circularity
            delete temp;
        }
        cout << "Dequeued from queue\n";
    }

    // Display the queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front); // Loop until we reach back to front
        cout << endl;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10); // Enqueue 10
    q.enqueue(20); // Enqueue 20
    q.enqueue(30); // Enqueue 30

    q.display(); // Display queue

    q.dequeue(); // Dequeue
    q.display(); // Display queue after dequeue

    q.enqueue(40); // Enqueue 40
    q.display(); // Display queue

    q.dequeue(); // Dequeue
    q.display(); // Display queue

    return 0;
}
