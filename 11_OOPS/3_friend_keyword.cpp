#include<iostream>

using namespace std;

class A{
    private:
        int x;

    public:
        //cons
        A(int _x): x(_x){}

        //getter/Setter
       int getX() const{
            return x;
        }        

        void setX(int _x){
            x = _x;
        }

        friend class B;       // now this code work: cout<< a.x << endl; 
        friend void fxn(const A &);    // friend fxn;
};

class B{

    public:
       
      void print(const A &a){
        //cout<< a.getX()<< endl;
        cout<< a.x << endl;         // error x is private variable
       }
};

void fxn(const A &a){
    cout<< a.x << endl;    // error 
}

int main(){

    A obj1(5);
    B obj2;

    obj2.print(obj1);

    fxn(obj1);

    return 0;
}