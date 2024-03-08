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
            front = 0;
            rare = 0;
        }

        //Enqueue
        void Enqueue(int val){
            if(rare == size){
                cout << "Cant Enqueue, Queue is FUll" << endl;
                return;
            }
            else{
                arr[rare] = val;
                rare++;
            }
        }

        //Dequeue
        void Dequeue(){
            if(rare == 0){
                cout << "Cant Dequeue, Queue is Empty" << endl;
                return;
            }
            else{
                arr[front] = -1;
                front++;

                if(front == rare){
                    front = 0;
                    rare = 0; 
                }
            }
        }

        //getFront
            int getFront(){

                if(rare == 0){
                     cout << "Cant get front element cause Queue is Empty" << endl;
                     return -1;
                }
                else{
                    return arr[front];
                }

            }
        //isempty
        bool isEmpty(){
            if(rare == 0){
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

    int x = q1.getFront();
    cout << "front element is : " << x<<endl;

    q1.Dequeue();
    q1.printQueue();


    x = q1.getFront();
    cout << "front element is : " << x<<endl;

    x = q1.getFront();
    cout << "front element is : " << x<<endl;

}
