#include<iostream>
#include"clsLinkedList.h"
using namespace std;
int main(){
Linkedlist<int>f;
f.append(3);
f.append(4);
f.append(5);
f.display();

f.Size();

cout<<endl;
f.display();
f.Reverse();
f.display();
cout<<endl;
f.Size();
f.Clear();

if(f.isempty())cout<<"the list is empty.\n";
else
cout<<"The list is not empty.\n";
}