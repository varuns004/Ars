#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int value){
        data=value;
        next=NULL;
    }
};

void insert(node* &head , int value){
    node* n= new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=n;
}
void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverse(node* &head){
    node* curr=head;
    node*prev=NULL;
    node* nxt;
    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nxt;
    }
    head=prev;
    return head;
}


node* palindrome(node* &head){
   
    node* start=head;
    node* temp=head;
    node* slow=head;
    node* fast=head;
   
    while(fast->next!=NULL && fast->next->next!=NULL ){
        fast=fast->next->next;
        slow=slow->next;
    }
      
    slow->next=reverse(slow->next);
    slow=slow->next;
    while(slow!=NULL){
       
        if(start->data!=slow->data){
            cout<<"not a palindrome";
            return temp;
        }
        
        start=start->next;
        slow=slow->next;
        
        }

    cout<<"palindrome"<<endl;
    return temp;
}
    
     


int main(){
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    display(head);
    palindrome(head);
    display(head);
       
    
    
    
    return 0;
    
}





