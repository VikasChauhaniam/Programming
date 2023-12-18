#include<iostream>
#include<vector>
#include<set>
using namespace std;



int oddPalindrome(string str){
    
int count = 0;
    for(int i=0; i<str.length(); i++){
        int s = i;
        int e = i;

        while(s>=0){

            if(str[s] == str[e]){
                cout << str.substr(s, e-s+1) <<endl;
                count++;
                s--;
                e++;
            }
            else{
                s= -1;
            }
        }

    }
    return count;

}


int evenPalindrome(string str){
    
int count = 0;
    for(int i=0; i<str.length(); i++){
        int s = i;
        int e = i+1;

        while(s>=0){

            if(str[s] == str[e]){
                cout << str.substr(s, e-s+1) <<endl;
                count++;
                s--;
                e++;
            }
            else{
                s= -1;
            }
        }

    }
    
    return count;
}


int main(){

    string s;

    cout << "enter string :";

    cin >> s;


    int count1 = oddPalindrome(s);
    int count2 = evenPalindrome(s);

    cout << "total palindorme : "<<count1 + count2<<endl;

    return 0;
}