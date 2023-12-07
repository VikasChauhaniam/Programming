#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<vector<int>> arr{
        {2, 5, 7, 9},
        {11, 15, 19, 21},
        {23, 28, 32, 35},
        {37, 38, 42, 44},
        {48, 50, 52, 55}
    };

    int find;
    int found = 0;

    cout << "Element Search : ";
    cin >> find;
    cout << endl;

    int row = arr.size();
    int col = arr[0].size();

    int totalElement = row * col;

    int start = 0;
    int end = totalElement-1;
    int mid = (start + end)/2;

    
    int rowIndex;
    int colIndex; 

    while(start<=end){

        rowIndex = mid/col;
        colIndex =  mid%col;

        int val = arr[rowIndex][colIndex];

        if(val == find){
            found = 1;
            break;
        }
        else if( val > find){
            end = mid -1;
        }
        else{
            start = mid + 1;
        }
        mid = (start + end )/2;
    }

    if(found){
        cout << "Found at  rowIndex : "<<rowIndex << " colIndex : "<<colIndex;
    }
    else{
        cout << "Not Found";
    }

    return 0;
}