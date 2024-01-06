#include<iostream>

using namespace std;


int fact(int n){

    if(n==1) return 1;

    return n * fact(n-1);    
}

int main(){

    int n;

    cout << "Enter the number N : ";
    cin >> n;

    int val = fact(n);

    cout <<"factorial of "<<n<< ":"<<val;

    return 0;
}