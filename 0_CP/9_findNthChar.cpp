#include<iostream>
using namespace std;
#include <algorithm>
#include<cmath>
int main(){

    string s = "1100";
    int r =1;
    int n = 2;
    string newS;

    int chrNeeded = ceil(n/(pow(2,r)))+1;
    
    
    for(int i =0; i<r; i++){
        newS ="";
        for(int j=0; j<chrNeeded; j++){

            
            
            if(s[j] == '0'){
                newS += '0';
                newS += '1';
            }
            if(s[j] == '1'){
                newS += '1';
                newS += '0';
            }
        }
        s = newS;
        cout << "char needed : "<< chrNeeded << endl;
        cout << "newS :" << newS << endl<< endl<< endl<< endl;

        chrNeeded = 2*chrNeeded;
        
    }

   cout << "nth char is:"<<newS[n];


    return 0;
}