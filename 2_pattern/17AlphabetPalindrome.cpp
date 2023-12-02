#include <iostream>
using namespace std;

int main(){

    int row;
    cout << "Enter row  : ";
    cin >> row ;


    for(int i = 0; i < row; i++){
        int lastChar;
        for (int j = 0; j <= i; j++)
        {
            cout << " " << (char)(65+j);
            lastChar = 65+j;
        }
        
        for (int j = 0; j < i; j++)
        {
            lastChar = lastChar-1;
            cout << " " << (char)(lastChar);
            
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}