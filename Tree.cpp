#include<iostream>
using namespace std;
class Node{
     public:
    int value;
    Node *left;
    Node *right;

    Node(int value){
        this->value=value;
        left=right=nullptr;
    }
};

class BST{
    public:
    Node * root;
BST(){
    root=nullptr;
}
Node * Insert(Node * r,int item){
    if(r==nullptr){
        Node *newnode=new Node(item);
        r=newnode;
    }else if(item < r->value ){
      r->left=  Insert(r->left,item);
    }else{
      r->right=  Insert(r->right,item);
    }
    return r;
}
void Insert(int item){
    root=Insert(root,item);
}

void preorderd(Node * r){// root->left->right
    if(r==nullptr)return;
    cout<<r->value<<'\t';
    preorderd(r->left);
    preorderd(r->right);
}
Node * Search(Node * r,int k){
   if(r==nullptr)return nullptr;
   else if(r->value==k)return r;
   else if(k < r->value) return Search(r->left,k);
   else  return Search(r->right,k);
} 
bool Search(int k){
    Node* result=Search(root,k);
    if(result==nullptr)return false;
    else
    return true;
} 
Node * Min(Node * r){
    if(r==nullptr)return nullptr;
    else if(r->left==nullptr)return r;
    else
    return Min(r->left);
}
Node * Max(Node * r){
    if(r==nullptr)return nullptr;
    else if(r->right==nullptr)return r;
else
return Max(r->right) ;
} 
Node * Delete(Node * r,int k){
    if(r==nullptr)return nullptr;
    if(k< r->value)r->left=Delete(r->left,k);
    else if (k> r->value)r->right=Delete(r->right,k);
    else
    {
        if(r->left==nullptr&&r->right==nullptr)//leaf node
        r=nullptr;
        else if(r->left!=nullptr&&r->right==nullptr)
        {
            Node* temp = r->left; 
            delete r;             
            return temp;        
        }
        else if(r->left==nullptr&&r->right!=nullptr)
        {
            Node* temp = r->right; 
            delete r;             
            return temp; 
        }
        else
        {
            Node * max=Max(r->left);
            r->value=max->value;
          r->left=  Delete(r->left,max->value);
        }
    }
    return r;
} 

};
int main(){

BST tree;
tree.Insert(10);
tree.Insert(20);
tree.Insert(30);
tree.Insert(40);
tree.Insert(50);
cout<<"Display the tree content \n";
tree.preorderd(tree.root);
cout<<"After Delete\n";
tree.Delete(tree.root,30);
tree.Delete(tree.root,40);

tree.preorderd(tree.root);
}