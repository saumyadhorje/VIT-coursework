#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

// Create new node
node* createNode(int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

// Insert into BST
node* insertNode(node* root, int data) {
    if (root == nullptr)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

// Inorder traversal
void inorder(node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Check if two trees are mirror images
bool isMirror(node* p, node* q) {
    // both null → mirror
    if (p == nullptr && q == nullptr)
        return true;

    // one null → not mirror
    if (p == nullptr || q != nullptr)
        return false;

    // values differ → not mirror
    if (p->data != q->data)
        return false;

    // check mirror: left-right swap
    return isMirror(p->left, q->right) &&
           isMirror(p->right, q->left);
}

int main() {
    node *root1 = NULL, *root2 = NULL;
    int choice, value;

    while (1) {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert in Tree 1\n";
        cout << "2. Insert in Tree 2\n";
        cout << "3. Display Tree 1 (Inorder)\n";
        cout << "4. Display Tree 2 (Inorder)\n";
        cout << "5. Check Mirror Image\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                root1 = insertNode(root1, value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                root2 = insertNode(root2, value);
                break;

            case 3:
                cout << "Tree 1 (Inorder): ";
                inorder(root1);
                cout << endl;
                break;

            case 4:
                cout << "Tree 2 (Inorder): ";
                inorder(root2);
                cout << endl;
                break;

            case 5:
                if (isMirror(root1, root2))
                    cout << "YES, Both trees are Mirror Images.\n";
                else
                    cout << "NO, Trees are NOT Mirror Images.\n";
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
