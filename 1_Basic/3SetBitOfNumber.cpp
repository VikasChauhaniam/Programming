#include <iostream>
using namespace std;

int SetBitCount(int num){
    int count=0;

    while(num){
        count += num & 1;
        num = num >> 1;
    }   

    return count;
}

int main(){

    int n;

    cout << "ENter n : ";
    cin >> n;

    int setBit = SetBitCount(n);

    cout << n << " set bits are  " << setBit << endl;

    return 0;
}