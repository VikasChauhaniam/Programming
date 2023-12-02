#include <iostream>
using namespace std;

int facto(int number){
    int f=1;

    while(number > 1){
        f = f * number;
        number--;
    }
    return f;
}

int main(){

    int num;
    cout << "Enter the number : ";
    cin >> num;

    int factNum = facto(num);

    cout << num << " Factorial is " <<  factNum;

    return 0;
}