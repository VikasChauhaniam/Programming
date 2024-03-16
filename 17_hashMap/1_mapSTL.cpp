#include<iostream>
using namespace std;

#include<map>

int main(){

    map<string, int> mp;

    //create
    pair<string, int> p = make_pair("vikas", 10);
    pair<string, int> q("viky", 20);

    pair<string, int> r;
    r.first = "vikcy";
    r.second = 30;

    //insert
    mp.insert(p);
    mp.insert(q);
    mp.insert(r);
    mp["vo"] = 40;

    
    for(auto i : mp){
        cout << i.first << " : " << i.second<<endl;
    }

    cout << mp.at("viky")<<endl;
    cout<< mp.size()<<endl;

    if(mp.find("vikass") != mp.end()){
        cout<<"found"<<endl;
    }
    else{
        cout<<"not found";
    }
    
    



    return 0;
}