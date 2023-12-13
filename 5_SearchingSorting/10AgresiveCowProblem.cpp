#include <iostream>
#include <vector>

using namespace std;

bool isPossibleSolutuion(vector<int>&DistArray,int cows,int mid){
    int cowCount =  1;
    int pos = DistArray[0];

    if(DistArray.size() < cows){
        return false;
    }

    for(int i=1; i<DistArray.size(); i++){
        if(DistArray[i] - pos >= mid){
            cowCount++;
            pos = DistArray[i];
          //  cout <<"=============start================="<<endl;
            
        }
      //  cout <<"distArray["<<i<<"]:"<<DistArray[i]<<" POS: "<<pos<<" mid: "<<mid<<endl;
        if(cowCount == cows){
            return true;
        }
     //   cout <<"==============end=============="<<endl;
        
    }
    return false;
}

int AgressiveCow(vector<int> DistArray,int cows){
    int mindist = 0;
    int maxdist = DistArray[DistArray.size() - 1] - DistArray[0];
    int ans = -1;
    
    while(mindist <= maxdist){
       int mid = (mindist + maxdist)/2;

       
         if(isPossibleSolutuion(DistArray, cows, mid)){
            ans = mid;
            mindist = mid + 1;
         //   cout << "ans : "<<ans<<" mindist : "<<mindist<<" maxdist : "<<maxdist<<endl;
        }
        else{
            maxdist = mid - 1;
        }
      //  cout << "00000000000000000000000000000000000000000"<<endl<<endl;

    }
    return ans;
}

int main(){

    int cows;
    cout<< "Enter total Number of cows : ";
    cin >> cows;

    int dist;
    cout<< "Enter total Number of dist in sorted order : ";
    cin >> dist;

    cout <<"enter data of array : ";
    vector<int> DistArray(dist, -1);

    for(int i=0; i<dist; i++){
        cin >> DistArray[i];
    }

    int ans = AgressiveCow(DistArray, cows);

    if(ans){
        cout << ans;
    }
    else{
        cout << "Invalid";
    }



    return 0;
}