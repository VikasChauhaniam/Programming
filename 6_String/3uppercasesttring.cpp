#include<iostream>

using namespace std;

void print(char str[]){

    //cout << "fxn array is : "<< str;
    int i=0;

    cout << "hi";
    while(str[i] != '\0'){
        int x = (int)str[i];
        if(x > 96){
            str[i] = (char)x-32;
        }
        i++;
    }
}
    

int main(){

    char str[100];

    cin.getline(str,50);

    cout << "ur line is ::: "<<str<<endl;

    print(str);
    cout << "ur line is ::: "<<str<<endl;
    return 0;
}