#include <iostream>
#include <vector>

using namespace std;

bool isPossibleSolutuion(vector<int>&Array,int woord_required,int mid){
    int wood_count =  0;

    // if(Array.size() < woord_required){
    //     return false;
    // }

    for(int i=Array.size()-1; i>=0; i--){

    
        if(Array[i] - mid > 0){
            wood_count += Array[i] - mid; 
        }
        if(wood_count >= woord_required){
            return true;
        }
    }
    return false;
}

int EKO(vector<int> Array,int woodRequired){
    int s = 0;
    int e = Array[Array.size()-1];
    int ans = -1;
    
    while(s <= e){
       int mid = (s + e)/2;

       
         if(isPossibleSolutuion(Array, woodRequired, mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

    }
    return ans;
}

int main(){

    int total_Wood_Required;
    cout<< "Enter total wood required : ";
    cin >> total_Wood_Required;

    int trees_in_forest;
    cout<< "Enter total Number of trees in foret : ";
    cin >> trees_in_forest;;

    cout <<"enter height of all tress  in sorted order : ";
    vector<int> treeArray(trees_in_forest, -1);

    for(int i=0; i<trees_in_forest; i++){
        cin >> treeArray[i];
    }

    int ans = EKO(treeArray, total_Wood_Required);

    if(ans > 0){
        cout << ans;
    }
    else{
        cout << "Invalid";
    }



    return 0;
}