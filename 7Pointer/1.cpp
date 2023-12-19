#include<iostream>

using namespace std;

int main(){

    int a =5;

    int *p = &a;

    cout << "&p : "<<*p<<endl;
     cout << "p : "<<p<<endl;

    //char *c = (char)&a; 

    return 0;
}