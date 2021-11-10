#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insertbst(node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    
    
    if(val<root->data){
        root->left=insertbst(root->left,val);
    }
    
    else{
        root->right=insertbst(root->right,val);
    }
    return root;
}
void display(node*root){
    if(root==NULL){
        return;
    }
    display(root->left);
    cout<<root->data;
    display(root->right);

}

int main(){
    struct node* root=NULL;
    root=insertbst(root,5);
    insertbst(root,1);
    insertbst(root,3);
    insertbst(root,4);
    insertbst(root,7);
    insertbst(root,2);
    display(root);
    return 0;
}