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
      cout<< ptr->Data<<" ";
      ptr = ptr->Next;
    }

}

int lengthofLL(Node* head){
    int length = 0;

    if(head == NULL){
        return length;
    }

    do{
        length++;
        head = head->Next;
    }while(head);

    return length;
}

void DeleteHead(Node* &head){

    Node* temp = head;
    head = head->Next;
    temp->Next = NULL;
    delete temp;
}

void DeleteTail(Node* &head){

    if(head->Next == NULL){
        head = NULL;
        return;
    }

    Node* prev = head;
    
    int i=1;

    while(i<lengthofLL(head)-1){
        prev = prev->Next;
        i++;
    }

    Node* temp = prev->Next; 
   prev->Next = NULL;

   temp->Next = NULL;
    

    delete temp;
    //delete prev;
}

void deleteAtPosition(Node* &head, int position){

    if(head==NULL){
        cout<<"empty link list, cant delete anything"<<endl;
    }
    else if(position == 1){
        DeleteHead(head);
    }
    else if(position == lengthofLL(head)){
        DeleteTail(head);
    }
    else if(position > lengthofLL(head) || position < 0){
        cout << "Wrong index of LL"<<endl;
    }
    else{
        int len = 1;
        Node* ptr = head;
        while(len < position-1){
            ptr = ptr->Next;
            len++;
        }
        Node* temp = ptr->Next;
        ptr->Next = temp->Next;

        temp->Next = NULL;
        delete temp;

    }

}

int main(){

    Node* Root = new Node(0);
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    Node* head = Root;

    Root->Next = first;
    first->Next = second;
    second->Next = third;
    third->Next = fourth;

    // int length = lengthofLL(head);

    // cout << "length : "<<length<<endl;

    
    // print(head);
    
    // DeleteTail(head);
    // cout<<endl<<"after deletetion"<<endl;

    // length = lengthofLL(head);

    // cout << "length : "<<length<<endl;


    print(head);
    deleteAtPosition(head, -3);
    cout<<endl;
    print(head);
}