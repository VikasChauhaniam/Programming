#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


// void inversionCount(vector<int>& arr){
//     int count = 0;
//     for(int i =0; i<arr.size(); i++){
//         for(int j =i+1; j<arr.size(); j++){
//             if(arr[i] > arr[j]){
//                 cout<<arr[i]<<" "<<arr[j]<<endl;
//                 count++;
//                 cout<<count<<endl;
//             }
//         }
//     }
    
// }

void merge(vector<int> &arr, int& count,int s,int mid,int e){

    vector<int> Newarr(arr.size());

    int i = s;
    int j = mid+1;
    int k = s;


    while(i<=mid && j<=e){
        

        if(arr[i] <= arr[j]){
            Newarr[k++] = arr[i++];
             
        }
        else{
            count += mid-i +1;
            Newarr[k++] = arr[j++];
            
        }
        
    }
    
    while(i<=mid){
         Newarr[k++] = arr[i++];
    }
    
    while(j<=e){
         Newarr[k++] = arr[j++];
    }

    for(int i = s; i<=e; i++){
        arr[i] = Newarr[i];
    }
    
}

void inversionCount(vector<int> &arr, int& count, int s, int e){
    
    if(s>=e) return;
    int mid = (s+e)/2;
   
    inversionCount(arr, count, s, mid);
    
    inversionCount(arr, count, mid+1, e);
    
    merge(arr, count,s, mid, e);
    
}

int main(){
    
    vector<int> arr{8, 4, 2, 1};
    
    int count =0;
    
    inversionCount(arr, count, 0, arr.size()-1);
    
    for(int i=0; i<arr.size(); i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
    cout<<count;

    return 0;
}