#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

// a project that simulates the queues associated with multiple vendor booths using a variety of data structures.

// linked list for customer queue
struct customerNode{
    string name; 
    string order; 

    customerNode(string n = " ", string o = " ") : name(n), order(o) {}

    customerNode*next = nullptr;
};

void output(customerNode*);
void addFront(customerNode*&head, string name);
void addTail(customerNode*&head, string name);
bool deletecustomerNode(customerNode*&head, int position); 
bool insertcustomerNode(customerNode*&head, int position, string name);
void deleteList(customerNode*&head);

int main() {  // Pasted in the Linked List code and methods below from Lab 17 code. 
    // seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Sample data
    array<string, 10> names = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Henry", "Iris", "Jack"};
    array<string, 5> coffeeOrders = {"Latte", "Cappuccino", "Espresso", "Americano", "Macchiato"};

    // Create a linked list of customersd
    customerNode*head = nullptr;
    int count = 0;
    int entry;
    // create a linked list of size of customers with data from arrays 
    for (int i = 0; i < names.size(); i++) {
        customerNode*newcustomerNode = new customerNode(names[i], coffeeOrders[i % coffeeOrders.size()]);
        newcustomerNode->next = head;
        head = newcustomerNode;
    }
    
    output(head);

    // // adding a customerNode to the tail of the list
    // float choice;
    // cout << "Enter a value to add to the tail of the list: "<< endl;
    // cout << "Choice --> ";
    // cin >> choice;
    // addTail(head, choice);
    // output(head);

    // // deleting a customerNode
    // cout << "Which customerNode to delete? " << endl;
    // output(head);
    // cout << "Choice --> ";
    // cin >> entry;
    // deletecustomerNode(head, entry); 
    // output(head);

    // // insert a customerNode
    // cout << "After which customerNode to insert 10000? " << endl;
    // cout << "Choice --> ";
    // cin >> entry;
    // insertcustomerNode(head, entry, 10000);
    // output(head);

    // deleting the linked list
    cout << "Deleting the entire list...\n";
    deleteList(head);
    output(head);


    return 0;
}
// function definitions   :   These come from the lab 17 linked list code.
void output(customerNode* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    customerNode * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->name << " " << current->order << endl;
        current = current->next;
    }
    cout << endl;
}
// Add a new customerNode to the front of the list
void addFront(customerNode*&head, string name, string order) { 
    customerNode *n = new customerNode;
    n->name = name;
    n->order = order;
    n->next = head;
    head = n;
}
// Add a new customerNode to the tail of the list
void addTail(customerNode*&head, string name, string order) {
    customerNode *n = new customerNode;
    n->name = name;
    n->order = order;
    n->next = nullptr;
    if (!head) {  // if the list is empty, add to front
        head = n;
        return;
    }
    customerNode *current = head;
    while (current->next)  // traverse to the end of the list
        current = current->next;
    current->next = n;  // link the new customerNode at the end
}
// insertcustomerNode function to insert val after the given 1-based position. Returns true on success.
bool insertcustomerNode(customerNode*&head, int entry, string name, string order ) {
    if (entry < 1) return false; // invalid position
    if (entry == 1) { // insert at the front
        addFront(head, name, order);
        return true;
    }
    customerNode *current = head;
    customerNode *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a customerNode between prev and current
    customerNode * newcustomerNode = new customerNode;
    newcustomerNode->name = name;
    newcustomerNode->order = order;
    newcustomerNode->next = current;
    prev->next = newcustomerNode;
    return true;    
}
// deletecustomerNode function to delete customerNode at 1-based position. Returns true if deleted.
bool deletecustomerNode(customerNode*&head, int entry) {
    if (entry < 1 || !head) return false; // invalid position or empty list 
    customerNode *current = head;
    customerNode *prev = head;
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
void deleteList(customerNode*&head) {
    customerNode *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}