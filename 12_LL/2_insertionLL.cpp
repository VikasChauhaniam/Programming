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

void insertAtHead(Node* &head,int val){

    Node* node = new Node(val);

    node->Next = head;
    head = node;
}


void insertAtTail(Node* &head,int val){

    Node* newNode = new Node(val);
    Node* ptr = head;

    while(ptr->Next){
        ptr = ptr->Next;
    }
    ptr->Next = newNode;
}

int main(){

    Node* Root = NULL;
    
    Node* head = Root;


    insertAtHead(head, 5);
    insertAtHead(head, 7);
    insertAtHead(head, 13);

    insertAtTail(head, 23);
    insertAtTail(head, 27);

    print(head);

}