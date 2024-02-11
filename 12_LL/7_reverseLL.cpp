#include<iostream>

using namespace std;

class Node{
    public:
        int Data;
        Node* Next;

        Node(){
            this->Data = 0;
            this->Next = NULL;
        }

        Node(int _val){
            this->Data = _val;
            this->Next = NULL;
        }

};

void  print(Node* &Root){
    Node* ptr = Root;

    while(ptr){
      cout<< ptr->Data<< " ";
      ptr = ptr->Next;
    }
    cout<<endl;

}

void ReversewithLoop(Node* &Root){

    Node* prev = NULL;
    Node* curr = Root;

    Node* forword;

    while(curr){
        forword = curr->Next;
        curr->Next = prev;
        prev = curr;
        curr = forword;
    }

    Root = prev;
}

Node* ReversewithRecursion(Node* &prev, Node* &curr){

    if(curr == NULL){
        return prev;
    }

    //solve one case
    Node* forwd = curr->Next;
    curr->Next = prev;

    prev = curr;
    curr = forwd;

    forwd = NULL;
    delete forwd;

    return ReversewithRecursion(prev, curr);

}

int main(){

    Node* Root = new Node(0);
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    Root->Next = first;
    first->Next = second;
    second->Next = third;
    third->Next = fourth;

    
    print(Root);

    ReversewithLoop(Root);

    print(Root);

    Node* prev = NULL;
    Node* curr = Root;
    Root = ReversewithRecursion(prev, curr);

    print(Root);
   
    

    

}