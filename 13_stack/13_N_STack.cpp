#include<iostream>

using namespace std;

class NStack{
    int *a, *top, * next;       //there are the arrays
    int n;                      //total number of stacks
    int size;                   //size of the array
    int freeSpot;               //keep track of freespot in the main array

    public:
        NStack(int _n, int _s): n(_n), size(_s){
            a = new int[size];
            top = new int[n];
            next = new int[size]; // next has 2 task-->1.can point to next element after top and 2. can point to next free space
            freeSpot = 0;

            for(int i=0; i<n; i++){
                top[i] = -1;
            }

            for(int i=0; i<size; i++){
                next[i] = i+1;
            }
            next[size-1] = -1;
        }

        //push value in some stackNumber
        bool push(int val, int stNum){
            //if stack is full
            if(freeSpot == -1){
                return false;
            }

            //1. find index
            int indx = freeSpot;

            //2. update freeSpot
            freeSpot = next[indx];

            //3. push value
            a[indx] = val;

            //4. update next
            next[indx] = top[stNum-1];

            //5. update top
            top[stNum-1] = indx;

            return true;
            

        }

         //pop value from some stackNumber
        int pop(int stNum){
            //if stack is empty
            if(top[stNum-1] == -1){
                return false;
            }

            //5. update top
            int indx =  top[stNum-1] ;

             //4. update next
             top[stNum-1] = next[indx];

             //3. pop value
            int popVal = a[indx];

            //2. update freeSpot
            next[indx] = freeSpot;

            //1. find index
            freeSpot =  indx;

           return popVal;

        }

        ~NStack(){
            delete[] a; 
            delete[] top; 
            delete[] next; 
        }
};


int main(){

    NStack  s(3, 6);

    cout<< s.push(10, 1) <<endl;
    cout<< s.push(20, 2) <<endl;
    cout<< s.push(30, 2) <<endl;
    cout<< s.push(40, 2) <<endl;
    cout<< s.push(50, 3) <<endl;
    cout<< s.push(60, 3) <<endl;
    cout<< s.push(70, 1) <<endl;

    cout<< s.pop(2) <<endl;
    cout<< s.pop(1) <<endl;
    cout<< s.pop(3) <<endl;

    return 0;
}