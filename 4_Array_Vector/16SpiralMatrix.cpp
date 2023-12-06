#include <iostream>
using namespace std;
#include <vector>

int main(){

    vector<vector<int>> arr{
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
        {26, 27, 28, 29, 30}
    };

    for(int i = 0; i < arr.size(); i++) 
    { 
        for(int j = 0; j <arr[0].size(); j++) 
        { 
            cout << arr[i][j] << " "; 
        } 
        cout<< endl; 
    }
    cout << "======================================================="<<endl;

//     int i=0, j=0;
//     int i_min=0, i_max = arr.size()-1;
//     int j_min=0, j_max = arr.size()-1;

//     while(true){

// //--------------------------------------------
//         while(j<=j_max){
//             cout << arr[i][j] << " "; 
//             j++;
//         }
//         cout << endl;
//         j--;
//         j_max=j-1;
//         i++;

// //--------------------------------------------
//         while(i<=i_max){
//             cout << arr[i][j] << " "; 
//             i++;
//         }
//         cout << endl;
//         i--;
//         i_max=i-1;
//         j--;
// //--------------------------------------------
//         while(j>=j_min){
//             cout << arr[i][j] << "."; 
//             j--;
//         }
//         cout << endl;
//         j++;
//         j_min=j+1;
//         i--;
// //--------------------------------------------
//         while(i>=i_min){
//             cout << arr[i][j] << " "; 
//             i--;
//         }
//         cout << endl;
//         i++;
//         i_min=i+1;
//         j++;

//         if((j_max == j_min) || (i_max == i_min)){
//             break;
//         }

//     }


int startingRow = 0;
int startingCol = 0;
int endingRow = arr.size()-1;
int endingCol = arr[0].size()-1;

int total_element  = arr.size() * arr[0].size();
int count = 0;

while(count < total_element){

    //Starting Row
    for(int j=startingCol; j<=endingCol; j++){
        cout << arr[startingRow][j] << " ";
        count++;
    }
    cout << endl; 
    startingRow++;
    

    //Ending Column
    for(int i=startingRow; i<=endingRow; i++){
        cout << arr[i][endingCol] << " ";
        count++;
    }
    cout << endl; 
    endingCol--;
   
    // Ending Row 
    for(int j=endingCol; j>=startingCol; j--){
        cout << arr[endingRow][j] << " ";
        count++;
    }
    cout << endl; 
    endingRow--;
    
    //Starting Column
    for(int i=endingRow; i>=startingRow; i--){
        cout << arr[i][startingCol] << " ";
        count++;
    }
    cout << endl; 
    startingCol++;
    

} 
    return 0;
}
