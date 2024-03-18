#include<iostream>
#include<vector>

using namespace std;

//Method 1----> Basic Recursion
int basicRecursion(int n){
    //base condition
    if(n==0 || n==1){
        return n;
    }

    return basicRecursion(n-1) + basicRecursion(n-2);
}

//Method 2 ---> Recursion + memoisation = topdown
int topDownRecursion(int n,vector<int> &dp){

    //base condtion
    if(dp[n] != -1){
        return dp[n];
    }

    //recursion
    dp[n] = topDownRecursion(n-1, dp) + topDownRecursion(n-2, dp);

    return dp[n];
}

//Method 3 ---> tebular = bottomUp
int bottomUpRecursion(int n){

    //base condtion
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i<=n; i++){
        //dp[n] = topDownRecursion(n-1, dp) + topDownRecursion(n-2, dp);
        //copied recursion code and replace fxn name with dp array
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//method 4 ---->space optimization on BottomUp method/tebular
int SpaceOptimizationBottomUpRecursion(int n){

    //base condtion
    
    int prev = 0;
    int next = 1;
    int curr;

    for(int i = 2; i<=n; i++){
        //dp[n] = topDownRecursion(n-1, dp) + topDownRecursion(n-2, dp);
        //copied recursion code and replace fxn name with dp array
        curr = prev + next;
        prev = next;
        next = curr;
    }

    return curr;
}

int main(){

    //febnocii series
    int n = 7;
    int f1 = basicRecursion(n);

    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    int f2 = topDownRecursion(n, dp); //Recursion + memoisaton


    int f3 = bottomUpRecursion(n); //tebular

    int f4 = SpaceOptimizationBottomUpRecursion(n); // tebular + space optimization

    cout << "f1 : "<<f1<<endl;
    cout << "f2 : "<<f2<<endl;
    cout << "f3 : "<<f3<<endl;
    cout << "f4 : "<<f4<<endl;
}


//which one is better

//  spaceOptimization > bottomUp > topDown > basicRecursion