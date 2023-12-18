#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

   
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    vector<string> strs2 = strs;
    vector<string> ans;
    vector< vector<string>> finalans;

    for(int i=0; i<strs.size(); i++){
            sort(strs[i].begin(), strs[i].end());
        }

    for(int i=0; i<strs.size(); i++){
            cout << strs[i]<<" ";
        }  
        cout<<endl;  
 
    for(int i=0; i<strs.size(); i++){
        
        int j = i+1;

       // cout<<"i="<<i<<"   "<<"j="<<j<<endl;//===================

        if(strs[i] != "0"){
        //    cout<<"===:strs[i]: "<<i<<"    "<<strs[i]<<endl; 
            ans.push_back(strs2[i]);
         //   cout<<"push element: "<<strs[i]<<endl;//===================
            while(j<strs.size()){
         //       cout<<"j="<<j<<endl;//=================================
                if(strs[i] == strs[j]){
          //          cout<<strs[i]<< "=="<< strs[j] <<" : "<<(strs[i] == strs[j])<<endl;//==============
                    ans.push_back(strs2[j]);
           //          cout<<"push element: "<<strs[i]<<endl;//===================
                   
                    strs[j] = "0";
                }
                j++;
          //      cout<<"value of j++"<<j<<endl;
            }
            finalans.push_back(ans);
       
            
            ans.clear();
            
          
        }
        // for(int i=0; i<strs.size(); i++){
        //     cout << strs[i]<<" ";
        // }  
        // cout<<"---------END-----------"<<endl;
    }
    


    // int count =1;
    // for(int i=0; i<strs.size(); i++){
    //        int j=i+1;
    //        if(j==strs.size() && strs[i] != "0"){
    //             cout << count <<" : "<< strs[i]<<endl;
    //             strs[i] = "0";
    //             ans.push_back(strs[i]);
    //        }
        
    //     while(j<strs.size()){
    //            if(strs[i] ==strs[j] && strs[i] != "0"){
    //                cout << count <<" : "<< strs[j]<<endl;
    //                ans.push_back(strs[j]);
    //                strs[j] = "0";

    //            }
    //            j++;
    //       }
    //       ans.push_back(strs[i]);
    //       strs[i] = "0";
    //       for(int i=0; i<strs.size(); i++){
    //         cout << strs[i]<<" ";
    //     }  
    //     cout<<endl;
    //       count++;
    //       finalans.push_back(ans);
    //       ans.clear();
    //  }
    
    for(auto vec : finalans){
        cout<<"-----------------------"<<endl;
        for(auto v : vec){
            cout << v<<" ";
        }
        cout <<endl;
    }

    return 0;
}