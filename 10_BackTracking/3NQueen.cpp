#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> leftUpperDiagonalCheck;
unordered_map<int, bool> leftLowerDiagonalCheck;


void printBoard(vector<vector <char>>chessBoard,int n, vector<vector <string>>& ans){
    
    vector <string> solution;

    for(int i=0; i<n; i++){
        string line;
        for(int j=0; j<n; j++){
            //cout<<chessBoard[i][j]<<" ";
            line += chessBoard[i][j];
        }
        solution.push_back(line);
        //cout<<endl;
    }
    ans.push_back(solution);

}

bool isSafe(vector<vector <char>>& chessBoard,int n,int row,int col){

    //row Checking--------------------------------------
    // int i =  row;
    // int j = col;


    // while(j >= 0){
    //     if(chessBoard[i][j] == 'Q'){
    //         return false;
    //     }
    //     j--;
    // }
    //upperDiagonal Checking-------------------------------
    // i =  row;
    // j = col;

    // while(j >= 0 && i >= 0){
    //     if(chessBoard[i][j] == 'Q'){
    //         return false;
    //     }
    //     j--;
    //     i--;
    // }

    //LowerDiagonal Checking-------------------------------
    // i =  row;
    // j = col;

    // while(j >= 0 && i < n){
    //     if(chessBoard[i][j] == 'Q'){
    //         return false;
    //     }
    //     j--;
    //     i++;
    // }


    //method 2 to reduce complexity of above 3 while loops
    if(rowCheck[row] == true || leftLowerDiagonalCheck[row + col] == true || leftUpperDiagonalCheck[row-col] == true){
        return false;
    } 
    //its safe to put Queen here
    return true;
}

void solve(vector<vector <char>>& chessBoard,int n,int col, vector<vector <string>>& ans){

    //BaseCase-> if solution found then print
    if(col >= n){
        printBoard(chessBoard, n, ans);
        return;
    }

    //Solve one Case
    for(int row = 0; row< n; row++){

        if(isSafe(chessBoard, n, row, col)){
            chessBoard[row][col] = 'Q';

            rowCheck[row] = true;
            leftLowerDiagonalCheck[row + col] = true; 
            leftUpperDiagonalCheck[row - col] = true; 

            solve(chessBoard, n, col+1, ans);
            //cout<<endl;

            //BackTracking
            chessBoard[row][col] = '.';
            rowCheck[row] = false;
            leftLowerDiagonalCheck[row + col] = false; 
            leftUpperDiagonalCheck[row - col] = false; 
        }
    }
    

}

int main(){

    int n = 9;

    vector<vector <char>> chessBoard(n, vector <char>(n, '.'));
    vector<vector <string>> ans;

    int col = 0;
    solve(chessBoard, n, col, ans);

    for(auto x : ans){
        for(auto y : x){
            for(auto z : y){
                cout<<z<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}