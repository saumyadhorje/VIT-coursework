#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

// Insert node at end
node* insertNode(node* head, int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (head == nullptr) { 
        return newnode;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

// Find and display nodes having even numbers
void findEven(node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    cout << "Even nodes: ";
    node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data % 2 == 0) {
            cout << temp->data << " ";
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
        cout << "No even numbers found";

    cout << endl;
}

// Display DLL
void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = nullptr;
    int choice, val;

    while (1) {
        cout << "\n*** DOUBLY LINKED LIST MENU ***\n";
        cout << "1. Insert node\n";
        cout << "2. Find even nodes\n";
        cout << "3. Display list\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                head = insertNode(head, val);
                break;

            case 2:
                findEven(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
