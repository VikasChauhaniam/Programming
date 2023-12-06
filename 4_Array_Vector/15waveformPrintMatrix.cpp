#include <iostream>
using namespace std;
#include <vector>

int main(){

    vector<vector<int>> arr{
        {1, 2, 3, 4, 5},
        {11, 12, 13, 14, 15},
        {21, 22, 23, 24, 25},
        {31, 32, 33, 34, 35},
        {41, 42, 43, 44, 45}
    };

    for(int i = 0; i < arr.size(); i++) 
    { 
        for(int j = 0; j <arr[0].size(); j++) 
        { 
            cout << arr[i][j] << " "; 
        } 
        cout<< endl; 
    }

    for(int i = 0; i < arr.size(); i++) 
    { 
        if(i%2 == 0){
            for(int j = 0; j <arr[0].size(); j++) 
            { 
                cout << arr[j][i] << " "; 
            } 
             cout<< endl; 
        }
        else{
            for(int j = arr[0].size()-1; j>=0; j--) 
            { 
                cout << arr[j][i] << " "; 
            } 
             cout<< endl; 
        }     
    }

    return 0;
}
