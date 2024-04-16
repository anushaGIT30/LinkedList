#include<iostream>
#include<vector>
using namespace std;
struct Node{

int data;
Node*next;

Node(int data1,Node*next1){
    data=data1;
    next=next1;

}

Node(int data1){
    data=data1;
    next=nullptr;
}

};


int main(){
    vector<int>arr={99,6,8,9};
  Node*y=new Node(arr[0]);
  cout<<y->data;  
  
    
}