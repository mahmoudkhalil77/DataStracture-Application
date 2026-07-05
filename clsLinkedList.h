#pragma once
#include<iostream>
using namespace std;

template<class T>
class Linkedlist{
    public:
class Node{
    public:
    T valeu;
    Node *next;
    Node *prev;
};
protected:
int _size=0;
private:
Node *head=nullptr;
Node *tail=nullptr;
public:
void insertBegin(T val){
    Node * newnode=new Node();
    newnode->valeu=val;
    newnode->next=head;
    newnode->prev=nullptr;
    if(head!=nullptr){
        head->prev=newnode;
    }else{
        tail=newnode;
    }
    head=newnode;
    _size++;

}
void display(){
    Node *temp=head;
    while(temp!=nullptr){
        cout<<temp->valeu<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
bool found(T k){
    bool flag=false;
    Node* temp=head;
    while (temp!=nullptr)
    {
        if(temp->valeu==k)flag=true;
        temp=temp->next;
    }
    return flag;
}
void insertbefore(T item,T newItem){
if(head==nullptr){
    cout<<"The List is Empty..\n";
    return;
}
if(head->valeu==item){
    Node * newnode=new Node();
    newnode->valeu=newItem;
    newnode->next=head;
    newnode->prev=nullptr;
    head->prev=newnode;
    head=newnode;
    return;
}
Node*temp=head;
while (temp!=nullptr&& temp->valeu!=item)
{
  temp=temp->next;
}
if(temp!=nullptr){
    Node * newnode=new Node();
    newnode->valeu=newItem;
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
}else
cout<<"The item is not found\n";
}
void append(T newItem){
    _size++;
    Node *newnode=new Node();
    newnode->valeu=newItem;
    newnode->next=nullptr;
    if(head==nullptr){
        newnode->prev=nullptr;
        head=tail=newnode;
        return;
    }
tail->next=newnode;
newnode->prev=tail;
tail=newnode;

}
void Delete(T item){
    if(head==nullptr)return;
    Node*temp=head;
    while (temp!=nullptr&&temp->valeu!=item)
    {
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"Item Not found\n";
        return;
    }
    if(temp==head){
        head=head->next;
        if(head!=nullptr)head->prev=nullptr;
        else tail=nullptr;
    }
    else if(temp==tail){
        tail=tail->prev;
        tail->next=nullptr;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    delete temp;
    _size--;
}
void Size(){
cout<< _size<<endl;
}
bool isempty(){
        return (head==nullptr);
    }
    void Clear(){
        Node *temp=head;
        while (temp!=nullptr)
        {
            Node* nexnode=temp->next;
            delete temp;
            temp=nexnode;
        }
        head=nullptr;
        _size=0;
        cout<<"the list has been cleared successfully.\n";
    }
    void Reverse(){
        Node *current=head;
        Node *temp=nullptr;
        while (current!=nullptr)
        {
            temp=current->prev;
            current->prev=current->next;
            current->next=temp;
            current=current->prev;

        }
        if(temp!=nullptr){
            head=temp->prev;
        }
        
    }
    Node* GetNode(int index){
        if(index>=_size||index<0)return nullptr;
        Node *current=head;
        if(unsigned int i=0;i<index;++i){
            current=current->next;
        }
        return current;
    }
    T GetItem(int index){
        Node *Item=GetNode(index);
        if(Item==nullptr)return nullptr;
        else
        return Item->valeu;
    }
    bool UpdateItem(int index,T newitem){
          Node *Item=GetNode(index);
          if(Item!=nullptr){
            Item->valeu=newitem;
            return true;
          }
          else
          return false;
    }
};


