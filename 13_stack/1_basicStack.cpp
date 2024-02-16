#include<iostream>
#include<limits.h>
using namespace std;

class Stack{

    public:
        int *arr;
        int size;
        int top;

        Stack(int size){
            arr = new int[size];
            this->size = size;
            top = -1;;
        }

        //function of stack

        void push(int data){                            //PUSH
            if(top == size-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            arr[++top] = data;
        }

        void pop(){                                     //pop
            if(top == -1){
                    cout<<"Stack Underflow"<<endl;
                    return;
            }
            top--;
        }

        int getTop(){ 
            if(top == -1){
                cout << "empty stack"<<endl;
                return INT_MIN;
            }                                  //top
            return arr[top];
        }

        int getSize(){                              //size
            return top+1;
        }

        bool isEmpty(){                             //isEmpty
            if(top != -1){
                return false;
            }
            return true;
        }


};

int main(){

    Stack s(2);
    s.push(5);
    s.push(9);
    s.push(10);

    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

    cout<<s.getTop()<<endl;
    s.pop();
    cout<<s.getTop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;
    s.pop();
    cout<<s.getTop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;




    return 0;
}
