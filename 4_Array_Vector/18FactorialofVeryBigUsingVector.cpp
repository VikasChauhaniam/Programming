#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printfxn(vector<int> a){

    for(int i : a){
        cout << i << "";
    }
    cout << endl<< endl;
}

int main(){

    vector<int> ans{1};
    vector<int> final;
    int carry = 0;
    int multiplier = 2;
    int fact = 987;

    while(multiplier<=fact){

        
        while(ans.size()>0){
            //cout<<"ans.size before="<<ans.size()<<endl;
            int mul = (ans.back() * multiplier) + carry; 

            //cout <<" multiplier:"<<multiplier<< " mul:"<<mul << endl;
            final.push_back(mul % 10);
            //cout <<"mul%10="<<mul%10<<endl;
            carry = mul/10;
            ans.pop_back();
            //printfxn(final);
        }
        
       // cout<<"."<<endl;
        while(carry){
           // cout<<"carry="<<carry<<endl;
            final.push_back(carry % 10);
            carry = carry/10;
            //printfxn(final);
        }
       // cout<<".."<<endl;
        reverse(final.begin(), final.end());
        ans = final;
        final.clear();
       // cout<<"ans.size end="<<ans.size()<<endl;
        multiplier++;

        
       
    }
    


    
   printfxn(ans);

    return 0;
}