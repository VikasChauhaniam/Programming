#include<iostream>
#include<vector>

using namespace std;

int main(){


    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    for(auto x : chars){
            cout << x << " ";
        }cout<< endl;


   

    int idx;

        for(int i=0; i<chars.size(); i++){
            idx = i;
           int count = 1;
           char ch = chars[i];
           chars[idx] = chars[i];
           i++;
           idx = i;
           while(i<chars.size() && ch == chars[i]){
               count++; 
               chars[idx] = count + '0';
               i++;
           }
           i--;
        }
        chars[++idx] = '\0';

        for(auto x : chars){
            cout << x << " ";
        }    

    return 0;
}