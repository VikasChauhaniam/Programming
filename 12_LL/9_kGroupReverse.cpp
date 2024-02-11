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


Node* K_ReverseLL(Node* &head, int k){
    //cout << head->Data << " " << endl;
    if(head == NULL){
        cout << "LL is Empty" << endl;
        return head;
    }
    if(k > lengthOfLL(head)){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forwd = curr->Next;

    int count = 0;

    while(count < k){
        count++;

        forwd = curr->Next;
        curr->Next = prev;

        prev = curr;
        curr = forwd;
    }

    //Recursion
    if(forwd){
        head->Next = K_ReverseLL(forwd, k);
    }
    

    return prev;

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

    
    print(Root);
   
    Root = K_ReverseLL(Root, 6);
    // int x = lengthOfLL(Root);
    // cout << x;
    print(Root);

    

}