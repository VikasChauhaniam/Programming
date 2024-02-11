#include<iostream>

using namespace std;

class Node{
    public:
        int Data;
        Node* Next;

        Node(){
            Data = 0;
            Next = NULL; 
        }

        Node(int _val){
            Data = _val;
            Next = NULL; 
        }

};

void print(Node* &head){
    if(head == NULL){
        cout << "LL is empty" << endl;
        return;
    }

    Node* ptr = head;

    while(ptr){
        cout << ptr->Data << " ";
        ptr = ptr->Next; 
    }cout<<endl<<endl;

    ptr = NULL;
    delete ptr;
}

void reverseNum(Node* &Num){

    Node* prev = NULL;
    Node* curr = Num;
    Node* forwd = NULL;

    while(curr){
        forwd = curr->Next;
        curr->Next = prev;
        prev = curr;
        curr = forwd;
    }
    forwd = NULL;
    curr = NULL;

    delete forwd;
    delete curr;

    Num = prev;
}

Node* SumLL(Node* &Num1, Node* &Num2){
    
    //Both LL empty
    if(Num1 == NULL && Num2 == NULL){
        return NULL;
    }
    //anyone of LL is empty
    if(Num1 == NULL)return Num2;
    if(Num2 == NULL)return Num1;

    
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    while(Num1 != NULL && Num2 != NULL){
        int sum = carry + Num1->Data + Num2->Data;

      //  cout <<"num1 :"<<Num1->Data<<endl;
      //  cout <<"num2 :"<<Num2->Data<<endl;

        carry = sum/10;
        int digit = sum%10;
        
        Node* newDigit = new Node(digit);

        if(ansHead == NULL){
            ansHead = newDigit;
            ansTail = newDigit;
        }
        else{
            ansTail->Next = newDigit;
            ansTail = newDigit;
        }
        Num1 = Num1->Next;
        Num2 = Num2->Next;
    }

    //print(ansHead);

    while(Num1){
        int sum = carry + Num1->Data;
        carry = sum/10;
        int digit = sum%10;

        Node* newDigit = new Node(digit);

        ansTail->Next = newDigit;
        ansTail = newDigit;
        Num1 = Num1->Next;
    }
   // print(ansHead);
    while(Num2){
        int sum = carry + Num2->Data;
        carry = sum/10;
        int digit = sum%10;

        Node* newDigit = new Node(digit);

        ansTail->Next = newDigit;
        ansTail = newDigit;
        Num2 = Num2->Next;
    }
    //print(ansHead);
     while(carry){
        int sum = carry;
        carry = sum/10;
        int digit = sum%10;

        Node* newDigit = new Node(digit);

        ansTail->Next = newDigit;
        ansTail = newDigit;
    }

    return ansHead;

}

int main(){

    Node* Num1 = new Node(2);
    Node* N1D2 = new Node(3);
    Node* N1D3 = new Node(4);
   // Node* N1D4 = new Node(6);
   // Node* N1D5 = new Node(9);
   // Node* N1D6 = new Node(7);
    Num1->Next = N1D2;
    N1D2->Next = N1D3;
   // N1D3->Next = N1D4;
   // N1D4->Next = N1D5;
   // N1D5->Next = N1D6;

    Node* Num2 = new Node(2);
    Node* N2D2 = new Node(1);
    Node* N2D3 = new Node(6);
    Node* N2D4 = new Node(4);
    Node* N2D5 = new Node(5);
    Node* N2D6 = new Node(7);
    Node* N2D7 = new Node(1);
   // Node* N2D3 = new Node(7);
    Num2->Next = N2D2;
    N2D2->Next = N2D3;
    N2D3->Next = N2D4;
    N2D4->Next = N2D5;
    N2D5->Next = N2D6;
    N2D6->Next = N2D7;

   // N2D2->Next = N2D3;

    //reverse both LL
    print(Num1);
    reverseNum(Num1);
    
    print(Num2);
    reverseNum(Num2);
    

    cout<<endl<<endl<<endl;

    //sum of LL
   Node* ans = SumLL(Num1, Num2); 

    //reverse of LL
   reverseNum(ans);

   print(ans);
    
    
    return 0;
}