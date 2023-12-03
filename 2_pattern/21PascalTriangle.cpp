#include <iostream>
using namespace std;

int main(){

    int num;
    cout << "num is : ";
    cin >> num;

    for(int i=1; i<= num; i++){
        for(int j=0; j<num-i; j++){
            cout << "   ";
        }
        int c =1;
        for(int j=1; j<=i; j++){
            cout << "  " << c << "  ";
            c = c * (i-j)/j;
        }
        cout << endl;

    }

    return 0;
}