#include<iostream>

using namespace std;


void counting(int n){

    if(n==0) return;

    

    counting(n-1);

    cout << n;
}

int main(){

    int n;

    cout << "Enter the number N : ";
    cin >> n;

    counting(n);

    return 0;
}