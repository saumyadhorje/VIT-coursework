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
    newnode->left = newnode->right = nullptr;
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

// Find minimum node in right subtree
node* findMin(node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Delete from BST
node* deleteNode(node* root, int key) {
    if (root == nullptr)
        return root;
//serach for key
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {  
        // Node found
        //if no child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        //only right child 
        else if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        //only left child
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            //both childern
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Count nodes
int countNodes(node* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Inorder traversal (optional display)
void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    node* root = nullptr;
    int choice, value;

    while (1) {
        cout << "\n\n--- BST Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Count Nodes\n";
        cout << "4. Display (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                root = insertNode(root, value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;

            case 3:
                cout << "Total nodes = " << countNodes(root) << endl;
                break;

            case 4:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
