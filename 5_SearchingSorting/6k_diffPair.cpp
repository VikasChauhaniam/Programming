#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){

    vector<int> arr{0,0,0};

    int i=0;
    int j=1;

    map<int, int> mp;

    int k;
    cout << "difference is equal to : ";
    cin >> k;
    cout << endl;

    sort(arr.begin(), arr.end());

    while(j<=arr.size()-1){

        if(arr[j] - arr[i] == k && i!=j){
            
            auto it = mp.find(arr[i]);
            if(it == mp.end()){
                mp[arr[i]] = arr[j];
                cout <<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            }
            
            i++;
            j++;
        }
        else if(arr[j] - arr[i] > k){
            i++;
        }
        else{
            j++;
        }
    }

    return 0;
}