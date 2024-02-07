#if !defined(BIRD_H)
#define BIRD_H

#include<iostream>
using namespace std;

class Bird{

    public:
        virtual void fly() = 0;
        virtual void eat() = 0;
        // classes that inherit this class
        // has to implement these virtual function.
};

class Sparrow : public Bird{
    private:
        void fly(){
            cout<< " sparrow is flying\n";
        }

        void eat(){
            cout << " sparrow is eating\n";
        }


};

class Eagle : public Bird{
    private:
        void fly(){
            cout<< " eagle is flying\n";
        }

        void eat(){
            cout << " eagle is eating\n";
        }
};


#endif // MACRO


