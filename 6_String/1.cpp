#include<iostream>
using namespace std;
#include <string.h>

int main(){

    char ch[100];

  //  cin >> ch;   //read input till space ,enter, tab, \n;
  //  cout <<"ur name is : "<< ch;

    // cin.getline(ch,9);
    // cout << ch;

    char arr[50];
    // cout << "enter"<<endl;
    // cin >> arr[3];
    // cin >> arr[50];

    cin.getline(arr,50);
    //cin >> arr;
    cout << arr;

    // int length = 0;

    
    // while(arr[length] != '\0'){
    //     length++;
    // }
    // cout << "length  is : "<<length;
    
    cout << arr[3]<<endl;
    cout << arr[4]<<endl;
    cout << arr[5]<<endl;
    cout << arr[8]<<endl;
    cout << arr[9]<<endl;

    cout << "length is : "<< strlen(arr);
return 0;
}