#include<iostream>
using namespace std;
template<class T>
class Array{
protected:
int _size=0;
T * _temp;

public:
T * originalAraay;
Array(int size=0){
    if(size<0){
        size=0;
        _size=size;
        originalAraay=new T[_size];
    }
}
~Array(){
    delete[] originalAraay;
}
bool setItem(int index,T val){
    if(index>=_size||_size<0)return false;
    else{
    originalAraay[index]=val
    return true;}
}
int Size(){
    return _size;
}
bool isEmpty(){
    return (_size==0?true:false);
}
void print(){
    for (int i = 0; i < _size; i++)
    {
        cout<<originalAraay[i]<<" ";
    }
    cout<<'\n';
}
void resize(int nwesize){
    if(nwesize<0)nwesize=0;

    _temp=new T[nwesize];
    if(nwesize<_size)_size=nwesize;
    for (int i = 0; i < _size; i++)
    {
        _temp[i]=originalAraay[i];
    }
    _size=nwesize;
    delete[]originalAraay;
    originalAraay=_temp;
}
T getitem(int index){
    return originalAraay[index];
}
void Reverse(){
    _temp=new T [_size];
    int counter=0;
    for (int i = _size-1; i>=0; i--)
    {
        _temp[counter]=originalAraay[i]
        counter++;
    }
    delete []originalAraay;
     originalAraay=_temp
}
void Clear(){
    _size=0;
    _temp=new T[0];
    delete []originalAraay;
    originalAraay=_temp;
}
bool Delete(int x){
if (x>=_size||x<0)
{
    return false;
}
_size--;
_temp=new T [_size];
for (int  i = 0; i < x; i++)
{
  _temp[i]=originalAraay[i];
}
for (int  i = x+1; i < _size+1; i++)
{
  _temp[i-1]=originalAraay[i];
}
delete[]originalAraay;

originalAraay=_temp;
return true;

}
int Find(T val){
    for (int i = 0; i < _size; i++)
    {
        if(originalAraay[i]==val)return i;
    }
    return -1;
}
bool DeleteItem(T val){
    int index=Find(val);
    if(index=-1)retrun false;
    Delete(index);
    return true;
}
bool Insert(T index,T val){
    if(index>_size||index<0)return false;
    _size++;
    _temp=new T[_size];
    for (int i = 0; i < index; i++)
    {
      _temp[i]=originalAraay[i];
    }
    _temp[index]=val;
    for (int i = index; i < _size-1; i++)
    {
      _temp[i+1]=originalAraay[i];
    }
    delete[]originalAraay;
    originalAraay=_temp;
    return true;
}
};
int main(){

}