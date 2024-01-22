#include<iostream>

using namespace std;

void printSubArray_util(string& s, int start, int end){

    if(start+end > s.size()){
        return;
    }
    

    cout<<s.substr(start, end)<<endl;
    printSubArray_util(s,start, ++end);

}

void printSubArray(string& s,int start,int end){

    for(int i=start; i<end; i++){
        printSubArray_util(s,i,1);
        cout<<endl;
    }
}


int main(){

    string s = "abcde";
    int start = 0;
    int end = s.size();
    printSubArray(s,start, end);
    return 0;
}