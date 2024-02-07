#include<iostream>

using namespace std;

class A{
    private:
        int x;
        int y;
        int z;

        A(int _z): z(_z){
            cout<<"private cons"<< endl;
        }

    public:
        //cons
        A(int _x, int _y): x(_x), y(_y){}

        //getter/Setter
       int getX() const{
            return x+y;
        } 

        int getZ() const{
            return z*z;
        }         

        void setX(int _x){
            x = _x;
        }

        friend class B;

};

class B{

    public:
        A print(int _i){
            return A(_i);   // running private constructor
        }
};




int main(){

    // A obj1(5,6);
    // cout << obj1.getX()<< endl;

  //  A obj2(3);                        //private constructor calling is not allowed directly
  //  cout << obj1.getZ()<< endl;

  B obj;
  A obj1 = obj.print(3);
  cout<< obj1.getZ()<<endl;
    return 0;
}