#include<iostream>
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

void deleteatpos(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        head=temp->next;
        delete temp;
        return;
    }
    int count = 1;

    while(count!=pos-1){
        temp=temp->next;
         count++;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

void countt(node* &head){
    int count =1;
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    cout<<count;
}

void insert(node* &head,int value){
    node* n = new node(value);

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

void display(node* & head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* insertatpos(node* &head,int pos,int value){
    node* temp=head;
    node* n=new node(value);
    if(pos==1){
        head=n;
        head->next=temp;
        return head;
    }
    int count =1;
    while(count!=pos-1){
        temp=temp->next;
        count++;

    }
    n->next=temp->next;
    temp->next=n;
}

void deletelist(node* &head,int key){
    
    node* temp=head;

    if(temp->data==key){
        head=temp->next;
        delete temp;
        return;
    }
    while(temp->next->data!=key){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

node* reverselist(node* &head){
    if(head==NULL){
        return head;
    }
    node* prev=NULL;
    node* curr=head;
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

int countrec(node* &head){
    if(head==NULL){
        return 0;
    }
    else{
    return 1 + countrec(head->next);
    }
}

void searchlist(node* &head,int key){
    if(head==NULL){
        return ;
    }

    if(head->data==key){
        cout<<"found";
    }
    

   searchlist(head->next,key);

}

int main(){
    node* head=NULL;
    insert(head,5);
    insert(head,7);
    insert(head,22);
    insert(head,9);
    insert(head,10);
    insert(head,11);

    display(head);
    deleteatpos(head,3);
    deleteatpos(head,1);
    deletelist(head,7);
    display(head);
    insertatpos(head,1,88);
    insertatpos(head,2,99);
    display(head);
    reverselist(head);
    display(head);
    cout<<countrec(head);
    searchlist(head,99);
    return 0;
}