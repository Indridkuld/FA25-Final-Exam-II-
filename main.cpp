#include <iostream>
#include <string>
#include <array>

using namespace std;

// a project that simulates the queues associated with multiple vendor booths using a variety of data structures.

// linked list for customer queue
struct customerNode {
    string name; 
    string order; 

    customerNode(string n = " ", string o = " ") : name(n), order(o) {}

    customerNode *next = nullptr;
};

int main() {  // Pasted in the Linked List code and methods below from Lab 17 code. 
    // Sample data
    array<string, 10> names = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Henry", "Iris", "Jack"};
    array<string, 5> coffeeOrders = {"Latte", "Cappuccino", "Espresso", "Americano", "Macchiato"};

    // Create a linked list of customers
    customerNode *head = nullptr;
    int count = 0;
    int entry;
    // create a linked list of size of customers with data from arrays 
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addFront(head, tmp_val);
    }
    output(head);

    // adding a node to the tail of the list
    float choice;
    cout << "Enter a value to add to the tail of the list: "<< endl;
    cout << "Choice --> ";
    cin >> choice;
    addTail(head, choice);
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry); 
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    cout << "Deleting the entire list...\n";
    deleteList(head);
    output(head);


    return 0;
}
// function definitions   :   These come from the lab 17 linked list code.
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
// Add a new node to the front of the list
void addFront(Node *&head, float val) { 
    Node *n = new Node;
    n->value = val;
    n->next = head;
    head = n;
}
// Add a new node to the tail of the list
void addTail(Node *&head, float val) {
    Node *n = new Node;
    n->value = val;
    n->next = nullptr;
    if (!head) {  // if the list is empty, add to front
        head = n;
        return;
    }
    Node *current = head;
    while (current->next)  // traverse to the end of the list
        current = current->next;
    current->next = n;  // link the new node at the end
}
// insertNode function to insert val after the given 1-based position. Returns true on success.
bool insertNode(Node *&head, int entry, float val) {
    if (entry < 1) return false; // invalid position
    if (entry == 1) { // insert at the front
        addFront(head, val);
        return true;
    }
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = val;
    newnode->next = current;
    prev->next = newnode;
    return true;    
}
// deleteNode function to delete node at 1-based position. Returns true if deleted.
bool deleteNode(Node *&head, int entry) {
    if (entry < 1 || !head) return false; // invalid position or empty list 
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    return true;
}
// delete the entire linked list and set head to nullptr
void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}