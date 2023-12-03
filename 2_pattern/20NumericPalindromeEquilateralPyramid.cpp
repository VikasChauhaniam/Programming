#include <iostream>
using namespace std;

int main(){

    int num;

    cout << "Enter Palindrome size : ";
    cin >> num;

    for(int i=0; i<num; i++){
        for(int j=0; j<num-1-i; j++){
            cout << "   ";
        }
        int k = 0;
        for(int j=0; j<=i; j++){
            cout <<" " << j+1 << " ";
            k = j+1;
        }
        for(int j=0; j<i; j++){
            cout << " " << k-1 << " ";
            k = k-1;
        }
        cout << endl;
    }

    return 0;
}