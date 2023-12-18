#include<iostream>
#include<vector>
using namespace std;


bool isPalindrome(string str){
    int s=0;
    int e=str.length()-1;

    while(s<=e){
        if(str[s] != str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;    
}

void substring(string s){
    vector<string> x;

    for(int i=0; i<s.length(); i++){
        for(int j=1; j<=s.length()-i; j++){
            //cout << s.substr(i,j)<<" ";
            x.push_back(s.substr(i,j));
        }
       // cout << endl;
    }

    for(int i=0; i<x.size(); i++){
        //cout << s[i]<< endl;;

        if(isPalindrome(x[i])){
            cout << x[i]<<endl;
        }
    }
    
}

int main(){

    string s;

    cout << "enter string :";

    cin >> s;

    substring(s);
    return 0;
}