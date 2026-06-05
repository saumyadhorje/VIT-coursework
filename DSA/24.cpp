#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* insertfront(node* head, int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    return head;
}

node* deleteatpos(node* head, int k) {

    if (head == nullptr) {
        cout << "List is empty" << endl;
        return head;
    }

    // delete first node
    if (k == 1) {
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    node* temp = head;
    node* prev = nullptr;

    while (temp != nullptr) {
        count++;

        if (count == k) {
            prev->next = temp->next;
            delete temp;
            return head;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Position out of range" << endl;
    return head;
}

void display(node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    node* head = nullptr;
    int choice, val, pos;

    while (true) {
        cout << "\n1. Insert Front\n2. Delete at Position\n3. Display\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                head = insertfront(head, val);
                break;

            case 2:
                cout << "Enter position: ";
                cin >> pos;
                head = deleteatpos(head, pos);
                break;

            case 3:
                display(head);
                break;

            case 4:
                return 0;
        }
    }
}
