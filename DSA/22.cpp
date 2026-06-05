//22. Singly Linked list with following options
//1. Insert from Front 2. Delete from Front 3. Display list 4. Exit

#include <iostream>
using namespace std;

struct node{
    int data;
    node*next;
};
//insert 
node*insertfront(node*head , int value){
node*newnode= new node();
newnode->data= value;
newnode->next=head;
head =newnode;
return newnode;

}
//delete
node*deletefront(node*head){
    if(head==nullptr){
        cout<<"list is empty , nothing to delete"<<endl;
        return;
    }
   node*temp=head;
   head=head->next;
   cout << "Deleted: " << temp->data << endl;
   delete temp;
   return head;
}
//display
void display(node*head){
    if(head==nullptr)
    cout<<"list is empty"<<endl;
    else{
        node*temp=head;
        cout<<"list:"<<endl;
        while(temp!=nullptr){
             cout << temp->data << " -> ";
            temp->next;
        }
         cout << "NULL\n";
    }
}
int main() {
    node* head = NULL;
    int choice, value;

    while (true) {
        cout << "\n----- Singly Linked List Menu -----\n";
        cout << "1. Insert from Front\n";
        cout << "2. Delete from Front\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                head = insertfront(head, value);
                break;

            case 2:
                head = deletefront(head);
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

    return 0;
}