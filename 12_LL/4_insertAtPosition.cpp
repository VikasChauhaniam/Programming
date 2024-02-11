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

    Node* newNode = new Node(val);

    if(head==NULL){
        head = newNode; 
    }
    else{
        newNode->Next = head;
        head = newNode;
    }
    
}
void insertAt(Node* &head,int position, int val){

    //check if linklist is empty
    if(head==NULL && position!=0){
        cout<<"link list is empty\n";
        return;
    }
    if(position==0){
        insertAtHead(head,val);
    }
    else{
        Node* front = head->Next;
        Node* back = head;
        int count = 1;

        while(count < position){
            if(front){
                back =  front;
                front = front->Next;
            }
            else{
                cout<<"Position is more then LL size\n";
                return;
            }
            
            count++;
        }

        Node* newNode = new Node(val);
        newNode->Next = front;
        back->Next = newNode;



    }
    

    

}

int main(){
    
    Node* Root = new Node(10);
    Node* first = new Node(20);
    Node* second = new Node(30);
    Node* third = new Node(40);
    Node* fourth = new Node(50);

    Root->Next = first;
    first->Next = second;
    second->Next = third;
    third->Next = fourth;
    Node* head = Root;
    
    
   
   insertAt(head, 9, 15);
//    insertAt(head, 1, 15);
//    insertAt(head, 0, 2); 
//    insertAt(head, 0, 5);
    
    print(head);

}