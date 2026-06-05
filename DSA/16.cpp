#include <iostream>
using namespace std;

// ------------- NODE STRUCTURE -------------
struct Node {
    int data;
    Node *left, *right;
    int height;
};

// ------------- HEIGHT FUNCTION -------------
int getHeight(Node* p) {
    if (p == nullptr)
        return 0;
    return p->height;
}

// ------------- BALANCE FACTOR -------------
int getBalance(Node* p) {
    if (p == nullptr)
        return 0;

    int leftHeight = getHeight(p->left);
    int rightHeight = getHeight(p->right);

    return leftHeight - rightHeight;
}

// ------------- CREATE NEW NODE -------------
Node* createNode(int value) {
    Node* n = new Node();
    n->data = value;
    n->left = n->right = nullptr;
    n->height = 1;  // new node is initially at height 1
    return n;
}

// ------------- RIGHT ROTATION -------------
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = t2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x; // x is new root
}

// ------------- LEFT ROTATION -------------
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = t2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y; // y is new root
}

// ------------- INSERT FUNCTION -------------
Node* insert(Node* root, int value) {

    // Normal BST insertion
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;  // duplicates not allowed

    // Update height of current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check balance factor
    int bf = getBalance(root);

    // --------- 4 ROTATION CASES ---------

    // Left Left Case
    if (bf > 1 && value < root->left->data)
        return rightRotate(root);

    // Right Right Case
    if (bf < -1 && value > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (bf > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (bf < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // no rotation needed
}

// ------------- DISPLAY (INORDER) -------------
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ----------------- MAIN MENU ------------------
int main() {
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "\n--- AVL TREE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Display (Inorder)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            root = insert(root, val);
        }
        else if (choice == 2) {
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
