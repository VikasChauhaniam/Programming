#include<iostream>

using namespace std;


void check(string& s1, int s, int e, int& ans){

    if(s>=e){
        return;
    }
    if(s1[s]!=s1[e]){
        ans=0;
        return;
    }
    check(s1,++s,--e, ans);
}

int main(){

    string s1 = "raceycar";
    

    int ans = 1;

    check(s1,0,s1.size()-1, ans);

    cout << ans;
    return 0;
}