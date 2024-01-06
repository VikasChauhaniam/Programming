#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

int solve(int n,int x,int y,int z){
    //base case

    if( n == 0 ){
        return 0;
    }

    int a = INT_MIN;
    if(n-x >= 0){
        a = solve(n-x, x, y, z) + 1;
    }

    int b = INT_MIN;
    if(n-y >= 0){
        b = solve(n-y, x, y, z) + 1;
    }

    int c = INT_MIN;
    if(n-z >= 0){
        c = solve(n-z, x, y, z) + 1;
    }

    int ans = max(a, max(b, c));

    return ans;
}

int main(){

    int n=7;
    int x=3,y=3,z=4;

    int ans = solve(n,x,y,z);

    cout<<"ans is: "<<ans<<endl;

    return 0;
}