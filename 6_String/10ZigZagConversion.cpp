#include<iostream>
#include<vector>

using namespace std;

int main(){

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    int rows;
    cout << "ROWS : ";
    cin >> rows;

    if(rows == 1){
        cout<<s;
    
    }

    vector<string> zigZag(rows);

    int direction = 1;
    int i = 0;
    int row = 0;

    while(true){

        if(direction == 1){
            while(row<rows && i<s.size()){
                zigZag[row++].push_back(s[i++]);
            }
            row -= 2;
        }
        else{
            while(row>=0 && i<s.size()){
                zigZag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        

        if(i>=s.size()) break;
        direction = !direction;
        
    }

    string ans;

    for(auto x : zigZag){
        ans += x;
        cout<<x<<endl;
    }

    //cout << ans;

    return 0;
}