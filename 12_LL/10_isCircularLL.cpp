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

bool isCircularTravel(Node* &Root){
    Node* head = Root;

    Node* ptr = Root->Next;

    while(ptr){
        if(ptr == head){
            return 1;
        }
        ptr = ptr->Next;
    }
    return 0;
}

bool isCircularSlowFast(Node* &Root){

    Node* slow = Root;
    Node* fast = Root;

    while(fast){

        fast = fast->Next;

        if(slow == fast){
            return 1;
        }

        if(fast){
            fast = fast->Next;
            slow = slow->Next;
        }

        if(slow == fast){
            return 1;
        }

    }

    return 0;
}

map<Node*, bool> m;

bool isCircularMap(Node* &Root){

    Node* ptr = Root->Next;
    m[Root] = true;

    while(ptr){
        if(m[ptr]  == true){
            return 1;
        }
        m[ptr] = true;
        ptr = ptr->Next;
    }
    return 0;
}


int main(){

    Node* Root = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    Node* fourth = new Node(5);

    Root->Next = first;
    first->Next = second;
    second->Next = third;
    third->Next = fourth;
    fourth->Next = Root;

    
    //print(Root);
   
    // bool c = isCircularTravel(Root);

    // bool c = isCircularSlowFast(Root);

    bool c = isCircularMap(Root);

    if(c){
        cout<< "yes"<<endl;
    }
    else{
        cout<< "NO"<<endl;
    }

    

}