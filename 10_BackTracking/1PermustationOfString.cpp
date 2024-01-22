#include<iostream>

using namespace std;

void permustation(string& s, int i){

    if(i >= s.size()){
        cout << s<< " ";
        return;
    }

    for(int j=i; j<s.size(); j++){

        swap(s[i], s[j]);

        permustation(s, i+1);

        //backTracking cause if use string s->then no need to back track
        swap(s[i], s[j]);

    }
}

int main(){

    string s = "abc";

    

    permustation(s, 0);
}