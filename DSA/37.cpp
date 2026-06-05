#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

// Insert from front
node* insertFront(node* head, int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = head;
    newnode->prev = nullptr;

    if (head != nullptr)
        head->prev = newnode;

    return newnode; // new head
}

// Delete nodes divisible by 3
node* deleteDivBy3(node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return head;
    }

    node* temp = head;

    while (temp != nullptr) {
        node* nextNode = temp->next;

        if (temp->data % 3 == 0) {
            // Case 1: deleting head
            if (temp->prev == nullptr) {
                head = temp->next;
                if (head != nullptr)
                    head->prev = nullptr;
            }
            // Case 2: deleting middle or last node
            else {
                temp->prev->next = temp->next;
                if (temp->next != nullptr)
                    temp->next->prev = temp->prev;
            }
            delete temp;
        }

        temp = nextNode;
    }

    cout << "Nodes divisible by 3 deleted.\n";
    return head;
}

// Display list
void display(node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = nullptr;
    int choice, val;

    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert from Front\n";
        cout << "2. Delete nodes divisible by 3\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                head = insertFront(head, val);
                break;

            case 2:
                head = deleteDivBy3(head);
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
