#include <iostream>
#include <string>
#include <array>

using namespace std;

// a project that simulates the queues associated with multiple vendor booths using a variety of data structures.

// Milestone 1: Coffee booth queue using custom linked list
struct Customer {
    string name; 
    string order; 

    Customer(string n = "", string o = "") : name(n), order(o) {}
};

// Node for linked list
struct Node {
    Customer data;
    Node* next;

    Node(Customer c) : data(c), next(nullptr) {}
};

// Custom linked list-based queue
class CoffeeBoothQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    CoffeeBoothQueue() : front(nullptr), rear(nullptr), size(0) {}

    // Add customer to queue (enqueue)
    void addCustomer(Customer c) {
        Node* newNode = new Node(c);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Remove and serve customer from queue (dequeue)
    Customer serveCustomer() {
        if (isEmpty()) {
            cout << "Queue is empty! No customers to serve." << endl;
            return Customer("", "");
        }

        Customer served = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;

        if (isEmpty()) {
            rear = nullptr;
        }

        return served;
    }

    // Check if queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Get queue size
    int getSize() const {
        return size;
    }

    // Display all customers in queue
    void displayQueue() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Current queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data.name << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~CoffeeBoothQueue() {
        while (!isEmpty()) {
            serveCustomer();
        }
    }
};

int main() {
    // Milestone 1: Initialize coffee booth queue
    CoffeeBoothQueue coffeeQueue;

    // Sample data
    array<string, 10> names = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Henry", "Iris", "Jack"};
    array<string, 5> coffeeOrders = {"Latte", "Cappuccino", "Espresso", "Americano", "Macchiato"};

    cout << "=== Milestone 1: Coffee Booth Queue (Linked List) ===" << endl << endl;

    // Add 3 initial customers
    for (int i = 0; i < 3; i++) {
        Customer c(names[i], coffeeOrders[i % 5]);
        coffeeQueue.addCustomer(c);
        cout << "Customer added: " << c.name << " (Order: " << c.order << ")" << endl;
    }

    cout << "\nQueue size: " << coffeeQueue.getSize() << endl;
    coffeeQueue.displayQueue();

    // Serve customers
    cout << "\n--- Serving Customers ---" << endl;
    while (!coffeeQueue.isEmpty()) {
        Customer served = coffeeQueue.serveCustomer();
        cout << "Served: " << served.name << " (Order: " << served.order << ")" << endl;
    }

    cout << "\nQueue size after serving: " << coffeeQueue.getSize() << endl;
    coffeeQueue.displayQueue();

    return 0;
}