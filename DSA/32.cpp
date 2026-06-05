#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

// INSERT FROM END
node* insertend(node* head, int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    // If list is empty
    if (head == nullptr) {
        return newnode;
    }

    node* temp = head;

    // Go to last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

// DELETE FROM FRONT
node* deletefront(node* head) {
    if (head == nullptr) {
        cout << "list is empty" << endl;
        return head;
    }

    // Only one node
    if (head->next == nullptr) {
        cout << "deleted: " << head->data << endl;
        delete head;
        return nullptr;
    }

    node* temp = head;
    head = head->next;

    head->prev = nullptr;
    temp->next = nullptr;

    cout << "deleted: " << temp->data << endl;

    delete temp;
    return head;
}

void display(node* head) {
    if (head == nullptr) {
        cout << "list is empty" << endl;
        return;
    }

    node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
