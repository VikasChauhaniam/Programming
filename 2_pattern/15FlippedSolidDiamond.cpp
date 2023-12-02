#include <iostream>
using namespace std;

int main(){

    int row;
    cout << "Enter row: ";
    cin >> row;
    int col = row*2;

    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
        {
            if(j>row-1-i && j<row+i){
                cout << "   ";
            }
            else{
                cout << " * ";
            }
        }
        cout << endl;
    }
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++)
        {
            if(j>i && j<col-i-1){
                cout << "   ";
            }
            else{
                cout << " * ";
            }
        }
        cout << endl;
    }
    

    return 0;
}