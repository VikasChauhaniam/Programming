#include<iostream>

using namespace std;

class Node{
    public:
        int Data;
        Node* Next;
        Node* Prev;

        Node(){
            this->Data = 0;
            this->Next = NULL;
            this->Prev = NULL;
        }

        Node(int _val){
            this->Data = _val;
            this->Next = NULL;
            this->Prev = NULL;
        }
};

void printLL(Node* &head){

    if(head == NULL){
        cout<< "LL is empty\n";
        return;
    }

    Node* ptr = head;

    while(ptr){
        cout<< ptr->Data << " ";
        ptr = ptr->Next;
    }
    cout<< endl;

    delete ptr;
}

int lengthLL(Node* &head){

    int length = 0;

    if(head == NULL){
        return length;
    }

    Node* ptr = head;

    while(ptr){

        length++;
        ptr = ptr->Next;

    }

    delete ptr;
    return length;

}

void InsertAtHead(Node* &head, Node* &tail, int val){

     Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->Next = head;
        head->Prev = newNode;

        head = newNode;
    }
}

void DeleteAtHead(Node* &head, Node* &tail){

    if(head == NULL){
        cout << "LL is empty"<<endl;
        return;
    }
    else if(head->Next == NULL){
        Node* temp = head;
        head = NULL;
        delete temp;
    }
    else{
        Node* temp = head;

        head = head->Next;
        head->Prev = NULL;

        delete temp;
    }
}


void InsertAtTail(Node* &head, Node* &tail, int val){

     Node* newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->Next = newNode;
        newNode->Prev = tail;

        tail = newNode;
    }
}

void DeleteAtTail(Node* &head, Node* &tail){

    if(head == NULL){
        cout << "LL is empty"<<endl;
        return;
    }
    else if(head->Next == NULL){
        Node* temp = head;
        head = NULL;
        delete temp;
    }
    else{
        Node* temp = tail;

        tail = tail->Prev;
        tail->Next = NULL;

        delete temp;
    }
}


void InsertAtPosition(Node* &head, Node* &tail,int val, int position){

    if(head == NULL || position <= 1){
        InsertAtHead(head, tail, val);
    }
    else if(position > lengthLL(head)){
        InsertAtTail(head, tail, val);
    }
    else{
        Node* newNode = new Node(val);

        Node* ptr = head;
        int count = 1;

        while(count != position){
            ptr = ptr->Next;
            count++;
        }

        newNode->Next = ptr;
        newNode->Prev = ptr->Prev;

        newNode->Prev->Next = newNode;
        ptr->Prev = newNode;

        ptr = NULL;
        delete ptr;
    }
}



void DeleteAtPosition(Node* &head, Node* &tail, int position){

    if(head == NULL || position <= 1){
        DeleteAtHead(head, tail);
    }
    else if(position >= lengthLL(head)){
        DeleteAtTail(head, tail);
    }
    else{
       // Node* temp;

        Node* ptr = head;
        int count = 1;

        while(count != position){
            ptr = ptr->Next;
            count++;
        }

        ptr->Prev->Next = ptr->Next;
        ptr->Next->Prev = ptr->Prev;

        delete ptr;


    }
}

int main(){

    Node* First = new Node(10);
    Node* Second = new Node(20);
    Node* Third = new Node(30);

    First->Next = Second;
    Second->Prev = First;

    Second->Next = Third;
    Third->Prev = Second;

    Node* head = First;
    Node* tail = Third;

    printLL(head);
    cout<<" length of LL : "<<lengthLL(head)<<endl;

    // InsertAtHead(head, tail, 9);
    // InsertAtHead(head, tail, 8);

    // InsertAtTail(head, tail, 4);
    // InsertAtTail(head, tail, 3);

    // InsertAtPosition(head, tail, 555, 10);

   // DeleteAtHead(head, tail);
    //DeleteAtHead(head, tail);
    //DeleteAtTail(head, tail);


    //InsertAtPosition(head, tail, 10);

    DeleteAtPosition(head, tail, 4);

    printLL(head);
    cout<<" length of LL : "<<lengthLL(head)<<endl;




    return 0;
}