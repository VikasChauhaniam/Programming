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

Node* reverse(Node* &head){
    
    Node* prev = NULL;
    Node* curr = head;
    Node* forwd = NULL;

    while(curr){
        forwd = curr->Next;
        curr->Next = prev;

        prev = curr;
        curr = forwd;
    }

    return prev;
}

bool isPalindrome(Node* &Root){
    
    //Empty LL
    if(Root == NULL){
        cout << "Empty LL" << endl;
        return 1;
    }

    //single element
    if(Root->Next == NULL){
        return 1;
    }

    //more then 1 element
    //step 1 : find middle of LL

    Node* slow = Root;
    Node* fast = Root;

    while(fast){
        fast = fast->Next;
        if(fast){
            fast = fast->Next;
            slow = slow->Next;
        }
    }

    //Step 2 : reverse LL ahead of slow
    Node* headOfReverse = reverse(slow->Next);

    // Step 3 : compare both

    while(headOfReverse){
        if(Root->Data == headOfReverse->Data){
            Root = Root->Next;
            headOfReverse = headOfReverse->Next;
        }
        else{
            return 0;
        }
    }

    return 1;

}
    


int main(){

    Node* Root = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(3);
    Node* fourth = new Node(2);
    Node* fifth = new Node(1);
    
    Root->Next = first;
    first->Next = second;
    second->Next = third;
    third->Next = fourth;
    fourth->Next = fifth;
    

    
    print(Root);


    bool x = isPalindrome(Root);

    if(x){
        cout<< "yes"<<endl;
    }
    else{
        cout<< "NO"<<endl;
    }
    
   
   

  

    

}