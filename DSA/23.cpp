#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at End
Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Delete from End using (temp->next->next != NULL)
Node* deleteEnd(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return head;
    }

    // Only one node
    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        return NULL;
    }

    Node* temp = head;

    // Stop at second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // temp->next is last node
    cout << "Deleted: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;

    return head;
}

// Display the list
void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "List: ";

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (true) {
        cout << "\n----- Singly Linked List Menu -----\n";
        cout << "1. Insert from End\n";
        cout << "2. Delete from End\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                head = insertEnd(head, value);
                break;

            case 2:
                head = deleteEnd(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
