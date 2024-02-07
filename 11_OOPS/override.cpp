#include<iostream>
using namespace std;

class parent{
    public:

        parent(){
            cout<<"im inside parent"<<endl;
        }
       void add(int& a, int& b){
            cout << a + b;
        }

};

class child : public parent{
    public:
        child(){
            cout<<"im inside child"<<endl;
        }

        void add(int& a, int& b){ //Overridding
            cout << a - b;
        }

};

int main(){

    int x = 10;
    int y = 6;

    //parent class Object
    parent* o1 = new parent();           // parent constructor run
    o1->add(x, y);                       //16

    // cout<<endl;

    //Child Class Object
    child* o2 = new child();              // child, parent both constructor run-->child inherit parent
    o2->add(x, y);                       //4
    
    // cout<<endl;

    // //UpCasting
    parent* o3 = new child();             // child, parent both constructor run-->actual object is child type and it is inherting parent
    o3->add(x, y);                       //16     //if virtual keyword added in front of parent funtion then 4
    
    // cout<<endl;

    // //DownCasting
    child* o4 = (child*)new parent();    // parent constructor run-->object of parent and it doesnt inherit
    o4->add(x, y);                       //4     //if virtual keyword added in front of parent funtion then 16
    
    cout<<endl;


    
}