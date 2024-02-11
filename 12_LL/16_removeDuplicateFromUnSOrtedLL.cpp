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


//map Method
void removeDuplicatemap(Node* &head){

    // Empty LL
    if(head == NULL){
        cout << "LL is empty"<< endl;
        return;
    }

    // One Element in LL
    if(head->Next == NULL){
        return;
    }

    int count = 0;

    Node* ptr = head;
    Node* temp = ptr->Next;

    map<int, bool> m;

    m[ptr->Data] = true;
    while(count <= lengthOfLL(head)){
        
        cout << "-"<<temp->Data<<endl;
        if(m[temp->Data] != true){

            m[temp->Data] = true;
            
            
            ptr = temp;
            temp = temp->Next;

            

        }
        else{
            Node* extra = temp;
            temp = temp->Next;
            
            ptr->Next = temp;

            extra = NULL;
            delete extra;
            
            
        }
        count++;
    }
   

}
    


int main(){

    Node* Root = new Node(4);
    Node* first = new Node(2);
    Node* second = new Node(1);
    Node* third = new Node(4);
    Node* fourth = new Node(3);
    Node* fifth = new Node(1);
    Node* sixth = new Node(1);
    Node* seventh = new Node(2);
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

    removeDuplicatemap(Root);

    print(Root);

}