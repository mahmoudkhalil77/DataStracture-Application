#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node * next;
    Node(){
        value=0;
        next=nullptr;
    }
};
class Queue{
    Node *front;
    Node *back;
    public:
    Queue(){
        front=back=nullptr;
    }
    bool isEmpty(){
        if(front==nullptr)return true;
        else
        return false;
    }
     void push(int item){
        Node *newnode=new Node();
        newnode->value=item;
        if(isEmpty()){
            front=back=newnode;
        }else{
            back->next=newnode;
            back=newnode;
        }
     }
     void display(){
        Node *temp=front;
        while (temp!=nullptr)
        {
            cout<<temp->value<<' ';
            temp=temp->next;
        }
        cout<<'\n';
     }
     int pop(){
        int n;
        if(isEmpty())
        cout<<"The queue is Empty.\n";
        else if(front==back){
            delete front;
            front=back=nullptr;
        }
        else
        {
            Node *dilptr=front;
            front=front->next;
            n=dilptr->value;
            delete dilptr;
        }
        return n;
     }
     int getfront(){
        return front->value;
     }
     void size(){
        int count=0;
        Node *temp=front;
        while (temp!=nullptr)
        {
            count++;
            temp=temp->next;
        }
        cout<<count<<endl;
     }
     bool isfound(int item){
        bool flag=false;
        Node *temp=front;
        while (temp!=nullptr){
            if(temp->value==item)flag=true;
            temp=temp->next;
        }
        return flag;
     }
     void Clear(){
        while (!isEmpty())
        {
            pop();
        }
        
     }
};

int main(){
Queue q;
int item;
for (int i = 0; i < 5; i++)
{
    cout<<"Please Enter the item .\n";
    cin>>item;
    q.push(item);
}
q.display();
q.Clear();
cout<<"display After clear";q.display();

}