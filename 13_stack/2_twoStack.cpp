#include<iostream>
using namespace std;

class Stack{

    private:
        int size;
        int* arr;
        int top1;
        int top2;

    public:
        Stack(int size){
            arr = new int[size];
            this->size = size;
            top1 = -1;
            top2 = size;
        }

        //function
    
        void push1(int data){
            if(top2 - top1 == 1){
                cout << "OVER FLOW at TOP1" << endl;
                return;
            }
            arr[++top1] = data;
        }

        void push2(int data){
            if(top2 - top1 == 1){
                cout << "OVER FLOW at TOP2" << endl;
                return;
            }
            arr[--top2] = data;
        }

        void pop1(){
            if(top1 == -1){
                cout << "UNDER FLOW at TOP1" << endl;
                return;
            }
            arr[top1--] = 0;
        }

        void pop2(){
            if(top2 == size){
                cout << "UNDER FLOW at TOP2" << endl;
                return;
            }
            arr[top2++] = 0;
        }

        void print(){
            int i = 0;
            while(i<size){
                cout << arr[i] << " ";
                i++;
            }cout<< endl;
        }
};

int main(){

    Stack s(10);

    s.pop1();
    s.pop2();

    s.push1(10);
    s.push2(100);
    s.print();

    s.push1(20);
    s.push2(200);
    s.print();

    s.push1(30);
    s.push2(300);
    s.print();

    s.push1(40);
    s.push2(400);
    s.print();

    s.push1(50);
    s.push2(500);
    s.print();

    s.push1(60);
    s.push2(600);
    s.print();

    s.pop1();
   // s.push2(500);
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    

    return 0;
}