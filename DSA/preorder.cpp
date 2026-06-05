#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* createnode(int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

node* insertnode(node* root, int data) {
    if (root == nullptr)
        return createnode(data);

    if (data < root->data)
        root->left = insertnode(root->left, data);
    else
        root->right = insertnode(root->right, data);

    return root;
}

// -------- PREORDER NON-RECURSIVE ----------
void preorder(node* root) {
    if (root == nullptr) {
        cout << "Tree is empty\n";
        return;
    }

    stack<node*> st;
    st.push(root);

    while (!st.empty()) {
        node* curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // push right first so left is visited first
        if (curr->right)
            st.push(curr->right);

        if (curr->left)
            st.push(curr->left);
    }
    cout << endl;
}

// ---------------- MAIN MENU ----------------
int main() {
    node* root = nullptr;
    int choice, data;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Preorder Traversal (Non-Recursive)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                root = insertnode(root, data);
                break;

            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
