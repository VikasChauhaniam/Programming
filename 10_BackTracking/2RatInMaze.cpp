#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int i, int j, int row, int col,int mazeArr[][4], vector< vector<bool>>& visited){

    if( (i>=0 && i<row) && (j>=0 && j<col) && 
        mazeArr[i][j] == 1 &&
        visited[i][j] == 0){
            return true;
        }
    return false;    
}


void mazeRun(int mazeArr[][4],int row,int col, int i, int j,vector< vector<bool>>& visited,vector<string>& path,string output){

    //base case--> reached final destination
    if(i == row-1 && j == col-1){
        path.push_back(output);
    }

    //Down Move  i+1, j
    if(isSafe(i+1,j, row, col, mazeArr, visited)){

        visited[i+1][j] = true;
        mazeRun(mazeArr, row, col, i+1, j, visited, path, output + 'D');

        //backtrack
        visited[i+1][j] = false;
    }
    //Left Move  i, j-1
    if(isSafe(i,j-1, row, col, mazeArr, visited)){

        visited[i][j-1] = true;
        mazeRun(mazeArr, row, col, i, j-1, visited, path, output + 'L');

        //backtrack
        visited[i][j-1] = false;
    }
    //Right move i, j+1
    if(isSafe(i,j+1, row, col, mazeArr, visited)){

        visited[i][j+1] = true;
        mazeRun(mazeArr, row, col, i, j+1, visited, path, output + 'R');

        //backtrack
        visited[i][j+1] = false;
    }
    //Up move i-1, j
    if(isSafe(i-1,j, row, col, mazeArr, visited)){

        visited[i-1][j] = true;
        mazeRun(mazeArr, row, col, i-1, j, visited, path, output + 'U');

        //backtrack
        visited[i-1][j] = false;
    }


}


int main(){

    int mazeArr[4][4] = { {1, 0, 0, 0},
                          {1, 1, 0, 1},
                          {1, 1, 0, 0},
                          {0, 1, 1, 1}
                    };

    if(mazeArr[0][0] == 0){
        cout<<"Path Not Found";
        return 0;
    }
    
    int row = 4;
    int col = 4;

    vector< vector<bool>> visited(row, vector<bool>(col, false));

    visited[0][0] = true;

    string output = "";
    vector<string> path;

    mazeRun(mazeArr, row, col, 0, 0, visited, path, output);

    if(path.size() == 0){
        cout<<"Path Not Found";
    }

    for(string pa: path){
        cout<< pa <<" ";
    }


   
    
}