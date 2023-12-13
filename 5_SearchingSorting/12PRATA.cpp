#include <iostream>
#include <vector>

using namespace std;

bool isPossibleSolutuion(vector<int>&Array,int paratha_required,int mid){
    int paratha_count = 0;
    
    int size = Array.size();

    for(int i=0; i<Array.size(); i++){
        int R = Array[i], j = 1;
        int time = 0;

        while(true){
            if(time + j*R <= mid){
                time += j*R;
                j++;
                paratha_count++;
            }
            else{
                break;
            }
        }
        if(paratha_count >= paratha_required){
            return true;
        }
    }
    
    return false;
}

int paratha(vector<int> Array,int parathaRequired){
    int s = 0;
    int e = Array[Array.size()-1]*((parathaRequired*(parathaRequired+1))/2);
    int ans = -1;

    

    while(s <= e){
       int mid = (s + e)/2;

   // cout <<"--------------------INITIALLY--------------------"<<endl;
    cout << "s:"<<s<<" e:"<<" mid:"<<mid<<" ans:"<<ans<<endl;
       
         if(isPossibleSolutuion(Array, parathaRequired, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }

    }
    return ans;
}

int main(){

    int total_paratha_Required;
    cout<< "Enter total paratharequired : ";
    cin >> total_paratha_Required;

    int number_of_chefs;
    cout<< "Enter total Number of chefs : ";
    cin >> number_of_chefs;;

    cout <<"rank of shefs in sorted order : ";
    vector<int> shefs_Rank_array(number_of_chefs, -1);

    for(int i=0; i<number_of_chefs; i++){
        cin >> shefs_Rank_array[i];
    }

    int ans = paratha(shefs_Rank_array, total_paratha_Required);

    if(ans > 0){
        cout << ans;
    }
    else{
        cout << "Invalid:"<<ans;
    }



    return 0;
}