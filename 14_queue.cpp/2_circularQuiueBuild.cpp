#include <iostream>
using namespace std;

class Queue{
    public:
        int *arr;
        int size;
        int front;
        int rare;

        //constructor
        Queue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rare = -1;
        }

        //Enqueue
        void Enqueue(int val){

            //overflow
            if((front == 0 && rare == size-1) || (rare == front -1) ){
                cout << "Cant Enqueue, Queue is FUll" << endl;
                return;
            }
            else if(front == -1){ //first insert
                front++;
                rare++;
                arr[rare] = val;
            }
            else if((rare == size-1) && (front !=0)){  //circular insert
                rare = 0;
                arr[rare] = val;
            }
            else{   //simple case
                rare++;
                arr[rare] = val;
            }
        }

        //Dequeue
        void Dequeue(){

             //underflow
            if((front == rare) && (rare ==  -1) ){
                cout << "Cant Dequeue, Queue is Empty" << endl;
                return;
            }
            else if((front == rare) && (front != -1)){ //first pop
                arr[front] = -1;
                front = -1;
                rare = -1;
                
            }
            else if(front == size-1){  //circular pop
                arr[front] = -1;
                front = 0;
                
            }
            else{   //simple case
                arr[front] = -1;
                front++;
            }
        }

        //getFront
            int getFront(){

                if((front == rare) && (rare ==  -1)){
                     cout << "Cant get front element cause Queue is Empty" << endl;
                     return -1;
                }
                else{
                    return arr[front];
                }

            }
        //isempty
        bool isEmpty(){
            if(rare == -1){
                return true;
            }
            return false;
        }

        void printQueue(){
            for(int i= 0; i< size; i++){
                cout << arr[i] << " "; 
            }cout<<endl;
        }
};

int main(){

    Queue q1 = Queue(5);

    q1.Enqueue(2);
    q1.printQueue();

    q1.Enqueue(3);
    q1.printQueue();

    q1.Enqueue(4);
    q1.printQueue();

    q1.Enqueue(5);
    q1.printQueue();

    q1.Enqueue(6);
    q1.printQueue();

    q1.Enqueue(7);
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Enqueue(6);
    q1.printQueue();

    q1.Enqueue(7);
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

     q1.Enqueue(2);
    q1.printQueue();

    q1.Enqueue(3);
    q1.printQueue();

    q1.Enqueue(4);
    q1.printQueue();

    q1.Enqueue(5);
    q1.printQueue();

    q1.Enqueue(6);
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();

    q1.Dequeue();
    q1.printQueue();


}
