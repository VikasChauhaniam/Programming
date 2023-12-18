#include<iostream>
#include <string.h>
using namespace std;

// void printArray(char str[]){

//     cout << "ur array is : "<<str;
// }

// void reverse(char str[],int l){

//     int i=0;
//     l =l-1;
//     while(i<=l){
//         char x = str[i];
//         str[i] = str[l];
//         str[l] = x;
//         i++;
//         l--;
//     }
    
//     printArray(str);

// }

// int findLength(char str[]){

//     int length = 0;

//     while(str[length] != '\0'){
//         length++;
//     }
//     return length;
// }

// void replace(char str[]){

//     int i =0;

//     while(true){

//         if(str[i] == '\0'){
//             break;
//         }
//         if(str[i] == ' '){
//             str[i] = '@';
            
//         }
//         i++;
//     } 
// }

// bool palindrome(char str[]){

//     int s = 0;
//     int e = strlen(str)-1;
//     cout << "string leng is  "<< e+1<<endl;
//     while(s<=e){
//         if(str[s++] != str[e--]){
//             return false;
//         }
//     }
//     return true;
// }

void uppercasew(char str[]){

    int i=0;
    cout << "hi";
    while(str[i] != '\0'){
        int x = (int)str[i];
        if(x > 96){
            str[i] = (char)x-32;
        }
    }
}
int main(){

    char str[100];

    cin.getline(str, 50);

    cout << "ur array is : "<<str <<endl;

    //replace(str);
  // bool x=  palindrome(str);

//    if(x){
//         cout << "palindrome";
//    }
//    else{
//     cout << "not palindrome";
//    }
int i=0;
    cout << "hi";
    cout<<"---start-----";
    //uppercasew(str);

    //int i=0;
    cout << "hi";
    while(str[i] != '\0'){
        int x = (int)str[i];
        if(x > 96){
            str[i] = (char)x-32;
        }
    }

    cout<<"---end-----"<<endl;
    cout << "ur array is : "<<str <<endl;
   // int l = findLength(str);

    //reverse(str, l);

    return 0;
}