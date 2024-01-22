#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void storeinArray(vector<int>& val, int n){

    if(n==0) return;

    val.push_back(n%10);
    n /= 10;

    storeinArray(val, n);

}

int main(){

    int n = 1234;

    int digits = int(log10(n)+1);

    vector<int> val;

    storeinArray(val, n);

    //reverse(val.begin(), val.end());

    // for(auto i : val){
    //     cout<<i<<endl;
    // }

    while(true){
        int extradigit = digits%3;

        float x =0;
        while(extradigit!=0){
            x += val.back();
            val.pop_back();
            extradigit--;
            if(extradigit){
                x *=10;
            }
        }
    }


    return 0;
}