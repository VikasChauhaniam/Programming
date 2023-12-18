#include<algorithm>
#include<iostream>
 using namespace std;

// bool comp(char a, char b){

//     return a!=b;
// }
void reorganizeString(string s) {
       sort(s.begin(), s.end());

        cout << s;
    }

 int main(){

    string s = "ababccccdd";

    reorganizeString(s);

    return 0;
 }   
