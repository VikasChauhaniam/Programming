#include <iostream>
using namespace std;

string EvenOdd(int number){
    if(number%2 == 0){
        return "Even";
    } 
    return "Odd";
}

int main(){

    int num;
    cout << "Enter the number : ";
    cin >> num;

    string NumType = EvenOdd(num);

    cout << num << " IS " <<  NumType;

    return 0;
}