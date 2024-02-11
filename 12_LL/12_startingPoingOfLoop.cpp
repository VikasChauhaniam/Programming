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

// bool isCircularTravel(Node* &Root){
//     Node* head = Root;

//     Node* ptr = Root->Next;

//     while(ptr){
//         if(ptr == head){
//             return 1;
//         }
//         ptr = ptr->Next;
//     }
//     return 0;
// }

bool isCircularSlowFast(Node* &Root){

    Node* slow = Root;
    Node* fast = Root;

    while(fast){

        fast = fast->Next;

        // if(slow == fast){
        //     cout<< "pointer match  Address slow : "<<slow<<endl;
        //     cout<< "Lpointer match Address fast: "<<fast<<endl;
        //     cout<< "loop value : "<<slow->Data<<endl;
        //     break;
        // }

        if(fast){
            fast = fast->Next;
            slow = slow->Next;
        }

        if(slow == fast){
            cout<< "pointer match  Address slow : "<<slow<<endl;
            cout<< "pointer match  Address fast: "<<fast<<endl;
            cout<< " match value : "<<slow->Data<<endl<<endl<<endl;
            

            slow = Root;

            while(slow != fast){
             slow = slow->Next;
             fast = fast->Next;
            }

            cout<< "Loop  Address slow : "<<slow<<endl;
            cout<< "Loop  Address fast: "<<fast<<endl;
            cout<< "loop value : "<<slow->Data<<endl;
            return 1;

        }

    }
    

    

    return 0;

    
}

// map<Node*, bool> m;

// bool isCircularMap(Node* &Root){

//     Node* ptr = Root->Next;
//     m[Root] = true;

//     while(ptr){
//         if(m[ptr]  == true){
//             return 1;
//         }
//         m[ptr] = true;
//         ptr = ptr->Next;
//     }
//     return 0;
// }


int main(){

    Node* Root = new Node(1);
    Node* first = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    Node* fourth = new Node(5);
    Node* fifth = new Node(6);
    Node* sixth = new Node(7);
    Node* seventh = new Node(8);
    Node* eight = new Node(9);
    Node* ninth = new Node(10);
    Node* tenth = new Node(11);
    Node* eleventh = new Node(12);

    Root->Next = first;
    first->Next = second;
    second->Next = third;
    third->Next = fourth;
    fourth->Next = fifth;
    fifth->Next  = sixth;
    sixth->Next = seventh;
    seventh->Next = eight;
    eight->Next = ninth;
    ninth->Next = tenth;
    tenth->Next = eleventh;
    eleventh->Next = second;

    
    //print(Root);
   
    // bool c = isCircularTravel(Root);

    bool loop = isCircularSlowFast(Root);

   // bool loop = isCircularMap(Root);

    if(loop){
        cout<< "yes"<<endl;
    }
    else{
        cout<< "NO"<<endl;
    }

    

}