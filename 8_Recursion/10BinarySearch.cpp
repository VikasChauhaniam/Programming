#include<iostream>

using namespace std;


int bs(int* arr, int s, int e, int key){
    int indx = -1;
    //cout<<"S:"<<s<<"    "<<"E:"<<e<<endl<<"============"<<endl;
    int mid = (s+e)/2;

    if(e<s){
        return indx;
    }
    if(arr[mid] == key){
        return mid;
    }
    

    return (key>arr[mid]) ? bs(arr,mid+1,e-1, key) : bs(arr,s,mid-1, key);


    return indx;

}

int main(){

    int arr[] = {2,5,7,9,11,14,17,19,23,37,32};

    int size = 11;
    int find = 23;

    int i = bs(arr,0,size-1, find);

    if(i==-1){
        cout << "element not found";
    }
    else{
        cout<<"element found at index :"<<i;
    }



    return 0;
}