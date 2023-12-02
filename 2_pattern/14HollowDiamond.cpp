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
        for (int j = 0; j <= i; j++)
        {
            if(j==0 || j==i){
                cout << " * ";
            }
            else{
                cout << "   ";  
            }
            cout << "   "; 
        }
        cout << endl;
    }
    for(int i = 0; i < row; i++){
        for (int j = 0; j < i; j++)
        {
            cout << "   ";
        }
        for (int j = 0; j < row-i; j++)
        {
            if(j==0 ||  j==row-i-1){
                cout << " * ";
            }
            else{
                cout << "   ";
            } 
            cout << "   "; 
        }
        cout << endl;
    }

    return 0;
}