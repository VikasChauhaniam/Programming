#include<iostream>

using namespace std;

class abc{
    public:
        int a;
        int b;

        abc(int _a, int _b): a(_a), b(_b){}

        void printabc(){
            cout<< a << " : " << b << endl;
        }
};

class xyz{
    public:
        static int x;
        static int y;

       // xyz(int _x, int _y): x(_x), y(_y){}   no this pass so cant initialise for object

        void printxyz(){
            cout<< x << " : " << y << endl;
        }
};

int xyz::x;    //static variable need to initailse for all objects like this
int xyz::y;


class lmn{
    public:
        static int l;
        static int m;

       // xyz(int _x, int _y): x(_x), y(_y){}   no this pass so cant initialise for object

        static void printlmn(){
            cout<< l << " : " << m << endl;
        }
};

int lmn::l;
int lmn::m;

int main(){

    //-----------------------------abc
    // abc obj1(1,2);
    // abc obj2(3,4);

    // obj1.printabc();
    // obj2.printabc();

    //-----------------------------xyz
    // xyz obj3;
    // obj3.x = 7;
    // obj3.y = 8;
    // obj3.printxyz();   //7:8

    // xyz obj4;
    // obj4.x = 9;
    // obj4.y = 10;
    // obj3.printxyz();   //9:10
    // obj4.printxyz();   //9:10

    lmn obj7;
    lmn::m = 10;
    lmn::l= 20;
    obj7.printlmn();


    return 0;
}