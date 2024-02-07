#include<iostream>

using namespace std;

int main(){

    // const int x = 5;
    //  x=10;      //error cant re -initalise const
    // cout<<x<<endl;

                            // 2. CONST WITH POINTERS
    // int*a = new int;
    // *a=2;
    // cout<< *a << endl;
    // delete a;
    // int b = 5;
    // a = &b;
    // cout<< *a << endl;

    // const int*a = new int;  //const data, non-const pointer
    // *a=2;                   // error
    // cout<< *a << endl;
    // delete a;
    // int b = 5;
    // a = &b;
    // cout<< *a << endl;

    // const int*a = new int(2);  //const data, non-const pointer
    // cout<< *a << endl;
    // delete a;
    // int b = 5;
    // a = &b;
    // cout<< *a << endl;

    // const int* a = new int(2);  //const data, non-const pointer
    // int const* a = new int(2);  //const data, non-const pointer
    // if we write const before *, then data will be const , not pointer.

    // int* const a = new int(2);  //NOn-const data, const pointer
    // *a=10;
    // cout<< *a << endl;
    // delete a;
    // int b = 5;
    // a = &b; //error, cant modify pointer
    // cout<< *a << endl;

    // const int *const a = new int(2);  //const data, const pointer
    // *a=10;               //error
    // cout<< *a << endl;
    // delete a;
    // int b = 5;
    // a = &b;             //error
    // cout<< *a << endl;

    // int x;
    // int fxn() const{
    //     x = 10       //error
    // }   

    // mutable int x;
    // int fxn() const{
    //     x = 10       //NO-error
    // }   


    // class className{
    //     int x;

    //     public:
    //     void func1() const{
    //         return;
    //     }
    //     void func2() {
    //         x =10;
    //         return x;
    //     }
    // }
    // void function1(const className &classObj){
    //     classObj.func1();   //no-error
    //     classObj.func2():   //error-> classObj is const object so its called function cant modify anything also.
    // }
    // className classObj;




    return 0;
}