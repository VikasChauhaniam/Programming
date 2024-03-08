#include<iostream>
#include<vector>

#include<algorithm>
#include<map>
using namespace std;



int main(){

 
    string s ="xxyyz";

     map<char,int> mp;
    
    for(char c : s){
        mp[c]++;
    }
    
    vector<int> v;
    for(auto x : mp){
        cout << x.first << ":" << x.second <<endl;
        v.push_back(x.second);

    }

    sort(v.begin(), v.end());

      for(auto i : v){
        cout << i << " ";
    }
    
    if(v.size() > 1){
        int removechar =0;
        for(int i =v.size() -1; i>0; i--){
            if(v[i] > v[0]){
                removechar++;
            }
	    }
	    if(removechar > 1){
	        cout<< "false";
	    }
    }
    cout << "true";
    
    

    return 0;
}