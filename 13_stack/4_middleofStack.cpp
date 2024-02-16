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

void findMiddle(Stack &s, int &valuesTObeTakenOut){

    //basecase
    if(valuesTObeTakenOut == 0){
        cout << "mid value = " << s.getTop()<<endl;
        return;
    }

    //solve 1 case
    valuesTObeTakenOut--;
    int temp = s.getTop();
    s.pop();

    //recursion
    findMiddle(s, valuesTObeTakenOut);

    //backtrack
    s.push(temp);
}


int main(){

    Stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(40);

    int findval = s.getSize()/2;
    findMiddle(s, findval);

   

    




    return 0;
}
