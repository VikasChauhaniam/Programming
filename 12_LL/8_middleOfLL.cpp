//Slow and Fast pointer Approch

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


int middleofLL(Node* &Root){
    if(Root == NULL){
        return -1;
    }
    if(Root->Next == NULL){
        return Root->Data;
    }

    Node* slow = Root;

    Node* fast = Root;
    while(fast){
        //cout<<slow->Data<<" ";
       
        fast = fast->Next;
        if(fast){
            fast = fast->Next;
            slow = slow->Next;
        }
    }
    return slow->Data;

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
   
    int val = middleofLL(Root);

    if(val == -1){
        cout<< "LL is empty"<<endl;
    }
    else{
        cout<<"middle element is: "<<val<<endl;
    }

    

}