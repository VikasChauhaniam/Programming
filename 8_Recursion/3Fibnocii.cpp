#include<iostream>

using namespace std;


int fib(int n){

    if(n==0 || n==1){
        //cout << n;
        return n;
    }
return fib(n-1) + fib(n-2);   
}

int main(){

    int n;

    cout << "Enter the number N : ";
    cin >> n;

    int val = fib(n);

   cout <<"factorial of "<<n<< ":"<<val;

    return 0;
}