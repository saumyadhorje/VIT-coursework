#include <iostream>
using namespace std;
#include <stack>
struct node{
    int data ;
    node*left ;
    node*right;

};

node*createnode(int data){
    node*newnode= new node();
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}

node* insertnode(node*root , int data){
if(root==nullptr){
    return createnode(data);
}
if(data<root->data){
    root->left=insertnode(root->left, data);
}
else{
    root->right=insertnode(root->right, data);
}
return root;
}

void inorder(node* root) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }

    stack<node*> st;
    node* curr = root;

    while (curr != NULL || !st.empty()) {

        // go to leftmost node
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // pop and print
        curr = st.top();
        st.pop();
        cout << curr->data << " ";

        // move to right subtree
        curr = curr->right;
    }

    cout << endl;
}

// ---------------- MAIN MENU ----------------
int main() {
    node* root = NULL;
    int choice, x;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal (Non-Recursive)\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                root = insertnode(root, x);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
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