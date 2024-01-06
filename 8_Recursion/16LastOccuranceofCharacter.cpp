#include<iostream>
#include <string.h>
using namespace std;

void ltor(string& s,char& key, int i, int& indx){
    //int indx = -1;

    if(i >= s.size()){
        return; 
    }

    if(s[i] == key){
        indx = i;
    }
    
    ltor(s, key, i+1, indx);
}

void rtol(string& s,char& key, int i, int& indx){
    //int indx = -1;

    if(i < 0){
        return; 
    }

    if(s[i] == key){
        indx = i;
        return;
    }
    
    rtol(s, key, i-1, indx);
}


int main(){

    string s = "abcddedgrgd";

    char key = 'g';
    int i=s.size()-1;
    int indx = -1;
    //ltor(s, key, i, indx);

    rtol(s, key, i, indx);
    cout << indx;
    return 0;
}