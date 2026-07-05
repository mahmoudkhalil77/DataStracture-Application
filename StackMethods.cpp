#include<iostream>
#include<string>
#include<vector>
#define ll long long
using namespace std;
class Node{
  public:
  int value;
  Node * next;
};
class Stack{
Node * top=nullptr;
public:

bool isempty(){
  if(top==nullptr)return true;
  else
  return false;
}
void push(int item){
  Node *newnode=new Node();
  newnode->value=item;
 if(isempty()){
  newnode->next=nullptr;
  top=newnode;
 }else
 {
  newnode->next=top;
  top=newnode;
 }
}
int pop(){
int value;
Node *dilptr=top;
value=top->value;
top=top->next;
delete dilptr;
return value;
}
int peek(){
  return top->value;
}
void display(){
Node *temp=top;
while (temp!=nullptr)
{
  cout<<temp->value<<" ";
  temp=temp->next;
}
cout<<'\n';

}
void Size(){
Node *temp=top;
int count=0;
while (temp!=nullptr)
{
count++;
  temp=temp->next;
}
cout<<'\n';
cout<<count<<endl;
}
bool isfound(int item){
  bool flag=false;
  Node * temp=top;
  while (temp!=nullptr)
  {
    if(temp->value==item)
      flag=true;
      temp=temp->next;
    
  }
  return flag;
}

};

int main(){
  Stack st;
  int item;
for(int i=0;i<5;++i){
  cout<<"Enter the items.\n";
  cin>>item;
  st.push(item);
}
st.display();
cout<<"the Item is deleted is : "<<st.pop()<<endl;
st.display();
st.Size();
}