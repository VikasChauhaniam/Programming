#include <iostream>
using namespace std;

int reverse(int num){
    int reverseNum=0;

    while(num){
        int digit = num%10;
        num = num/10;
        reverseNum = reverseNum*10 + digit;
    }

    return reverseNum;
}

int main(){

    int n;

    cout << "ENter n : ";
    cin >> n;

    int reverseNum = reverse(n);

    cout << n << " reverse is " << reverseNum << endl;

    return 0;
}