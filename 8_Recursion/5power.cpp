#include<iostream>

using namespace std;


int power(int n, int pow){

    if(pow==1){
        //cout << n;
        return n;
    }
    
return n * power(n,pow-1);  
}

int main(){

    int n;

    cout << "Enter the number N : ";
    cin >> n;

    int pow;

    cout << "Enter the number pow : ";
    cin >> pow;

    int val = power(n,pow);

   cout <<"factorial of "<<n<< ":"<<val;

    return 0;
}