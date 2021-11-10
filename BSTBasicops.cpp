#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insert(node* &root, int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else root->right=insert(root->right,val);

    return root;

}
void display(node* &root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

void levelorder(node* &root){
  if(root==NULL) return;
  queue<node *> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
      node* n=q.front();
      q.pop();
      if(n!=NULL){
          cout<<n->data<<" ";
          if(n->left) q.push(n->left);
          if(n->right)  q.push(n->right);
      }
      else if(!q.empty())  q.push(NULL);

  }
}
int sum(node* &root){
    if(root==NULL) return 0;
    return sum(root->left)+sum(root->right)+root->data;
}
int count(node* &root){
    if(root==NULL) return 0;
    return count(root->left)+count(root->right)+1;
}

int main(){
    node* root=NULL;
    root=insert(root,3);
    insert(root,4);
    insert(root,5);
    insert(root,9);
    insert(root,10);
    display(root);
    levelorder(root);
    cout<<endl;
    cout<<count (root);
    return 0;
}

