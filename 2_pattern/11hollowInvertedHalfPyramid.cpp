#include <iostream>
using namespace std;

int main(){

    int row;
    cout << "Enter row: ";
    cin >> row;

    for(int i = 0; i < row; i++){
        for (int j = 0; j < row-i; j++)
        {
            if(i!=0 && j!=0){  
                
                if(j==row-i-1){
                    cout << " * ";
                }    
                else{
                    cout << "   ";
                }
            }
            else{
                 cout << " * ";
            }
            
        }
        cout << endl;
    }

    return 0;
}