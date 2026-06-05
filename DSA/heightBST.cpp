#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* createnode(int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

// FIXED: Must return node*
node* insertnode(node* root, int data) {
    if (root == nullptr) {
        return createnode(data);
    }

    if (data < root->data)
        root->left = insertnode(root->left, data);
    else
        root->right = insertnode(root->right, data);

    return root;
}

int height(node* root) {
    if (root == nullptr)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

void inorder(node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;
    int choice, value;

    while (1) {
        cout << "\n---- BST MENU ----\n";
        cout << "1. Insert\n";
        cout << "2. Height of Tree\n";
        cout << "3. Display (Inorder)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insertnode(root, value);
                break;

            case 2:
                cout << "Height of Tree = " << height(root) << endl;
                break;

            case 3:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
