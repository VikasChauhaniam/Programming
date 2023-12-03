#include <iostream>
using namespace std;
#include <math.h>

int SetBitadd(int num, int bit){
    
  
    int newNumber = num | (int)(pow(2,(bit-1)));
    return newNumber;
}

int main(){

    int number, bit;

    cout << "ENter number and bit : ";
    cin >> number >> bit;

    int newNum = SetBitadd(number, bit);

    cout  << " nuew number is  " << newNum << endl;

    return 0;
}