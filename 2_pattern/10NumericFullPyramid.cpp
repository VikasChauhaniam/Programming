#include <iostream>
using namespace std;

int main(){

    int row;
    cout << "Enter row: ";
    cin >> row;

    for(int i = 0; i < row; i++){
        for (int j = 0; j < row-i-1; j++)
        {
            cout << "   ";
        }
        for (int j = 0; j < i+1; j++)
        {
            cout << " " << j+i+1 << " ";  
        }
        for (int j = 0; j < i; j++)
        {
            cout << " " << (i*2)-j << " ";  
        }
        cout << endl;
    }

    return 0;
}