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

void insertAtHead(Node* &head,Node* &tail,int val){

    Node* newNode = new Node(val);

    if(head==NULL && tail==NULL){
        head = newNode; 
        tail = newNode; 
    }
    else{
        newNode->Next = head;
        head = newNode;
    }
    
}


void insertAtTail(Node* &head,Node* &tail,int val){

    Node* newNode = new Node(val);

    if(head==NULL && tail==NULL){
        head = newNode; 
        tail = newNode; 
    }
    else{
        tail->Next = newNode;
        tail = newNode;
    }
    
}

int main(){
   
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail, 5);
    insertAtHead(head,tail, 7);
    insertAtHead(head,tail, 13);

    insertAtTail(head,tail, 23);
    insertAtTail(head,tail, 27);

    print(head);

}