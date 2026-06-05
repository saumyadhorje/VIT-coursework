#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

// Insert from front
node* insertfront(node* head, int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = head;
    newnode->prev = nullptr;

    if (head != nullptr)
        head->prev = newnode;

    return newnode;
}

// Delete nodes having EVEN values
node* deleteeven(node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }

    node* temp = head;

    while (temp != nullptr) {
        node* nextnode = temp->next;

        if (temp->data % 2 == 0) {
            // Case: deleting head
            if (temp == head) {
                head = temp->next;
                if (head != nullptr)
                    head->prev = nullptr;
            }
            else {
                temp->prev->next = temp->next;
            }

            // Fix next node
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;

            delete temp;
        }

        temp = nextnode;
    }

    return head;
}

// Display list
void display(node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "List: ";
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert from Front\n";
        cout << "2. Delete Even Nodes\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                head = insertfront(head, value);
                break;

            case 2:
                head = deleteeven(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
