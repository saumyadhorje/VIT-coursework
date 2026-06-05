//31. Doubly Linked list with following options
//1. Insert from Front 2. Delete from end 

#include <iostream>
using namespace std;

struct node{
    node*next;
    node*prev;
    int data;
};

node*insertfront(node*head , int data ){
     // If list is empty
    
    node*newnode=new node();
    newnode->data=data;
    if (head == nullptr) {
        head = newnode;
        return head;
    }
    newnode->next=head;
    newnode->prev=nullptr;
    head->prev=newnode;
    head = newnode;
    return head;
}

node*deletefront(node*head){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
        return head;
    }
    if(head->next==nullptr && head->prev==nullptr){
delete head;
return nullptr;
    }
    
    node*temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->prev=nullptr;
    temp->next=nullptr;
    delete temp;
return head;
}