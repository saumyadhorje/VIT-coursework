#include <iostream>
using namespace std;

struct node{
    int data;
    node*next;
    node*prev;

};

node*insertfront(node*head, int data){
    node*newnode= new node();
    newnode->data=data;
    newnode->next=head;
    head->prev=newnode;
    newnode->prev=nullptr;
    newnode=head;
    return newnode;
}

node*swapfirstlast(node*head){
    if(head->next==nullptr){
        return head;
    }
    if(head==nullptr){
        return head;
    }
    //if 2 nodes
    if(head->next->next==nullptr){
        node*temp=head->next;
        head->prev=temp;
        temp->next=head;
        head->next=nullptr;
        temp->prev=nullptr;
        head=temp;
    
    }
    //if mode than two nodes
    else{
        node*first=head;
        node*last=head;
        while(last->next!=nullptr){
            last=last->next;

        }
        node*firstnext=first->next;
        node*lastprev=last->prev;
        last->next=firstnext;
        firstnext->prev=last;
        lastprev->next=first;
        first->prev=lastprev;
        last->prev=nullptr;
        first->next=nullptr;
        head=last;
        return head;
    }
}
void display(node*head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    node* head = nullptr;

    head = insertfront(head, 10);
    head = insertfront(head, 20);
    head = insertfront(head, 30);
    head = insertfront(head, 40);

    cout << "Original DLL: ";
    display(head);

    head = swapfirstlast(head);

    cout << "After swapping first & last: ";
    display(head);

    return 0;
}