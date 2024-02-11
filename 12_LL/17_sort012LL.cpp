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

    Node* ptr = head;

    while(ptr){
        cout << ptr->Data << " ";
        ptr = ptr->Next; 
    }cout<<endl<<endl;
}

void SortWithReplace(Node* &head){

    //empty
    if(head == NULL){
        cout << "empty LL" << endl;
        return;
    }

    //one element
    if(head->Next == NULL){
        return;
    }

    //More then 1 element
    Node* ptr = head;

    int NumOfOnes = 0;
    int NumOfTwos = 0;
    int NumOfThrees = 0;

    //counting number of 1, 2,  3
    while(ptr){
        if(ptr->Data == 1){
            NumOfOnes++;
        }
        else if(ptr->Data == 2){
            NumOfTwos++;
        }
        else if(ptr->Data == 3){
            NumOfThrees++;
        }
        ptr = ptr->Next;
    }

    // placing 1 2 3 in sorted order
    ptr = head;
    while(NumOfOnes--){
        ptr->Data = 1;
        ptr = ptr->Next;
    }
    while(NumOfTwos--){
        ptr->Data = 2;
        ptr = ptr->Next;
    }
    while(NumOfThrees--){
        ptr->Data = 3;
        ptr = ptr->Next;
    }

}

void SortWithOutReplace(Node* &head){

    //empty
    if(head == NULL){
        cout << "empty LL" << endl;
        return;
    }

    //one element
    if(head->Next == NULL){
        return;
    }

    //More then 1 element
    Node* firstNodeHead = new Node(-1);
    Node* firstNodeTail = firstNodeHead;

    Node* secondNodeHead = new Node(-1);
    Node* secondNodeTail = secondNodeHead;

    Node* thirdNodeHead = new Node(-1);
    Node* thirdNodeTail = thirdNodeHead;


    Node* ptr = head;
    
    //counting number of 1, 2,  3
    while(ptr){
        
        //save a variable for deletion
        
        if(ptr->Data == 1){
            firstNodeTail->Next = ptr;
            firstNodeTail = ptr;

            ptr = ptr->Next;
            firstNodeTail->Next = NULL;

        }
        else if(ptr->Data == 2){
            secondNodeTail->Next = ptr;
            secondNodeTail = ptr;

            ptr = ptr->Next;
            secondNodeTail->Next = NULL;

        }
        else if(ptr->Data == 3){
            thirdNodeTail->Next = ptr;
            thirdNodeTail = ptr;

            ptr = ptr->Next;
            thirdNodeTail->Next = NULL;

        }  
    }

    //one LL is not empty
    if(firstNodeTail->Data != -1){

        // head point to first LL, delete firstNodeHead
        Node*temp = firstNodeHead;
        head = firstNodeHead->Next;
        temp = NULL;
        delete temp;

        if(secondNodeTail->Data != -1){
            
            firstNodeTail->Next = secondNodeHead->Next;

            //delete secondNodeHead
            Node*temp = secondNodeHead;
            temp = NULL;
            delete temp;

            if(thirdNodeTail->Data != -1){
                secondNodeTail->Next = thirdNodeHead->Next;

                // delete thirdNodeHead
                Node*temp = thirdNodeHead;
                temp = NULL;
                delete temp;
            }
        }
        else if(thirdNodeTail->Data != -1){
            firstNodeTail->Next = thirdNodeHead->Next;

            // delete thirdNodeHead
            Node*temp = thirdNodeHead;
            temp = NULL;
            delete temp;            
        }
        
        
    }
    else{// one LL is empty
        if(secondNodeTail->Data != -1){
    
            // head point to second LL, delete secondNodeHead
            Node*temp = secondNodeHead;
            head = secondNodeHead->Next;
            temp = NULL;
            delete temp;

            if(thirdNodeTail->Data != -1){
                secondNodeTail->Next = thirdNodeHead->Next;

                // delete thirdNodeHead
                Node*temp = thirdNodeHead;
                temp = NULL;
                delete temp; 
            }
        }
        else{
            if(thirdNodeTail->Data != -1){

                // head point to third LL, delete thirdNodeHead
                Node*temp = thirdNodeHead;
                head = thirdNodeHead->Next;
                temp = NULL;
                delete temp;
            }

        }
    }


}

int main(){

    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(1);
    Node* fourth = new Node(1);
    Node* fifth = new Node(3);

    first->Next = second;
    second->Next = third;
    third->Next = fourth;
    fourth->Next = fifth;

    Node* head = first;

    print(head);

    //SortWithReplace(head);
    SortWithOutReplace(head);

    print(head);

    return 0;
}