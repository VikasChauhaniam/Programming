#include<iostream>
using namespace std;

class abc{
    public:
        int age;

        int operator +(abc& obj2){
            int firstValue = this->age;
            int secondValue = obj2.age;

            return firstValue - secondValue;
        }

};

int main(){

    abc object1;
    abc object2;

    object1.age = 5;
    object2.age = 10;
                                    // here Object1.function(object2) is called
                                    // function is + operator
                                    // object2 is passed as argument
                                    // + operator is overloaded
    cout << object1 + object2;  
}