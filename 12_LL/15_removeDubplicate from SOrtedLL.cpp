//Slow and Fast pointer Approch

#include<iostream>
#include<map>
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


int lengthOfLL(Node* &head){
    int length = 0;

    if(head == NULL){
        return length;
    }

    Node* temp = head;

    do{
        length++;
        temp = temp->Next;
    }while(temp);

    return length;
}



void removeDuplicate(Node* &head){

    // Empty LL
    if(head == NULL){
        cout << "LL is empty"<< endl;
        return;
    }

    // One Element in LL
    if(head->Next == NULL){
        return;
    }

    //More then 1 Element in LL
    Node* curr = head;

    while(curr){

        if((curr->Next) && (curr->Data == curr->Next->Data)){
            Node* temp = curr->Next;

            curr->Next = curr->Next->Next;

            temp = NULL;
            delete temp;
        }
        else{
            curr = curr->Next;
        }
    }

}
    


int main(){

    Node* Root = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(2);
    Node* fifth = new Node(3);
    Node* sixth = new Node(3);
    Node* seventh = new Node(4);
    Node* eighth = new Node(5);
    
    Root->Next = first;
    first->Next = second;
    second->Next = third;
    third->Next = fourth;
    fourth->Next = fifth;

    fifth->Next = sixth;
    sixth->Next = seventh;
    seventh->Next = eighth;
    

    
    print(Root);

    removeDuplicate(Root);

    print(Root);

}