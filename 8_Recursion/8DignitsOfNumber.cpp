#include<iostream>

using namespace std;

void printDigit(int n){

    if(n==0) return;

    int x = n%10;

    n = n/10;

    printDigit(n);
    cout << x <<" ";

}

int main(){

    int n =5640;

    printDigit(n);
    return 0;
}