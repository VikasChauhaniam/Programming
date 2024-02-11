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
      cout<< ptr->Data<<endl;
      ptr = ptr->Next;
    }

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

}