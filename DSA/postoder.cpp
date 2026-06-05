#include<iostream>
using namespace std;
#include<stack>
struct node{
    int data; 
    node*left ;
    node*right;
};

node*createnode(int data){
    node*newnode=new node();
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;

}
//insert
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
//traversal
void postorder(node*root){
    if(root==nullptr){
        cout<<"tree is empty";
        return ;
    }
    stack<node*>s1;
    stack<node*>s2;

    while(!s1.empty()){
        node*curr=s1.top();
        s1.pop();
        s2.push(curr);
    
if(curr->left){
    s1.push(curr->left);
}
if(curr->right){
    s1.push(curr->right);
}
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();

    }
    cout<<endl;
}
int main() {
    node* root = NULL;
    int choice, x;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Postorder Traversal (Non-Recursive)\n";
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
                cout << "Postorder Traversal: ";
                postorder(root);
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