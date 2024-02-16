#include<iostream>

// ---------------------------------------------------------------------------------------------------------------------------Creation of Class

class Animal{


};

// -----------------------------------------------------------------------------------------------------State/Properties and  behavior of Class

class Animal{

    //state
    int legs;           //Default Private ---> so we cant access from outside of class.
                                              // but can be accessed from inside class only.
                                              //to acess private from outside class we need to use GETTERS & SETTTERS

   public:             // public  --> can be accessed from inside and outside of class
                                     // all the data under public will now become public                                              
    string name;


    //Behavious
    void eat(){
        
    }

    void sleep(){

    }

    // ========================================================================GETTERS AND SETTERS METHODS
    int getSomeValue(){
        return legs;          // legs is private member
    }

    void serSomeValue(int x){
        legs = x;
    }

    // we can  also do the above funxtion like this           //THIS : this a pointer to current object
    void serSomeValue(int legs){
        this->legs = legs;
    }

};


// ==========================================================================Object Creation of class

int main(){

    Animal a1;    //Static Memory
    a1.name;

    Animal* p = new Animal;             // Dynamic Memory
    (*p).name;
     p->name;

    delete p;                            // it gonna delete the allocated memory

    return 0;
}

//-==============================================================================CONSTRUCTOR

//      1.  Constructor is Called as Soon as Object is Created     It helps to initalise some values.
//      2.  No return Type
//      3.  its name Same as Class Name

class Dog{

    private:
    int b;

    public:
    int a;

    //*********************************************DEFAUT Constructor
    Dog(){
        this->a = 5;
        this->b = 6;
    }

    //*********************************************PARAMETERISED Constructor
    Dog(int age){
        this->a = age;
        this->b = 6;
    }

    //*********************************************Copy Constructor

    //Copy Constructor----->it is called when one object is copied into another object
    Dog(Dog& obj){
        this->a = obj.a;
        this->b = obj.b;
    }
};

int main(){

    Dog obj1;
    Dog obj2(10);
    
    Dog* p = new Dog;

    //Object copy------->copy constructor is called
    Dog obj3 = obj1;
    Dog obj4(obj1);
}


// ============================================================================================DESTRUCTOR

//It helps to free the memory

//         1. IF object is created Statically then destructor will be called automatically
//         2. IF object is created Dynamacally then destructor will be called manually                delete obj;
//         3. No return type
//         4. no parameter
//          5. it same as ~ className


//-----------------------------------------------------------------------------------------------------------------------4 PILLIOR of OOPS


//  1.    Incapuslation 
//  3.  Polymorphism
//  2.   Inheritance
//  4.    Abstraction   : implementation hiding

//-===============================================================================================Incapsulation

// [data Member | member Function] 
//  class is encapsulation

//--PEREFECT ENCAPUSULATION : all DATA MEMEBER are private, to access them use getter setter
// abstraction can be achieveied  with the use of Access Modifier.

//================================================================================================Inheritance

class A{


};

class B: public A{               // thats how we inheritance

}


       Class A  |            Inheritance in Class B
                        Public       Protected        private
       ---------|---------------------------------------------- 
       Public   |       public       protected        private
       Protected|       protected    protected        private
       Private  |       NA              NA              NA 


 publuc inherit of class B      :   can be accessed in classB and outside Class
 protected inherit of class B   :   can be accessed in classB
 private inherit of class B     :   can be accessed in classB   


//******************************************************************Type of Inheritance

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 1. Single

class Parent{

};

class child :public Parent{

};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 2. multilevel

class GrandParent{

};

class Parent :public GrandParent{

};

class child :public Parent{

};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ 3. multiple

class ParentA{
    public:
        int var;
};

class ParentB{
    public:
        int var;
};


class child :public ParentA, public ParentB{

};


if ParentA and ParentB both has same variableName that is inheriteded into child class, then complier get confuse which one to run
to run it we need to use SCOPE RESOLUTION operator

child obj;

obj.ParentA :: var; 
obj.ParentB :: var;


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   4. hierarchical

class Parent{

};

class childA :public Parent{

};

class childB :public Parent{

};
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  5. hybrid

It is combination of any other inheritance.
     


//======================================================================================================PolyMorphism

//  1. CompileTime Polymorphism
//  2. RunTime Polymorphism

//************************************************************************ComplieTime Polymorphism

//  1. Funtion OverLoading
//  2. Operator OverLoading

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& Function Overloading

class A{
    public:

        int sum(int a, int b){
            return a + b;
        }

        int sum(int a, int b, int c){
            return a + b + c;
        }

        int sum(int a, float b){
            return a + b;
        }
}

we can change 
                1. number of variable
                2. type of vaiable
                3. can not change return type.

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& Operato Overloading

// Syntex

return_type Operator operator_symbol(){

}

//Example : using + for subtraction

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
//************************************************************************RunTime Polymorphism
//Overridding   funtions---->modify the function in childClass which is inherited from parentClass
// virtual Keyword
// upCasting and DownCastin

#include<iostream>
using namespace std;

class parent{
    public:
        parent(){
            cout<<"im inside parent"<<endl;
        }

       virtual void add(int& a, int& b){
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

    cout<<endl;

    //Child Class Object
    child* o2 = new child();              // child, parent both constructor run-->child inherit parent
    o2->add(x, y);                       //4
    
    cout<<endl;

    //UpCasting     //virtual keyword
    parent* o3 = new child();             // child, parent both constructor run-->actual object is child type and it is inherting parent
    o3->add(x, y);                       //16     //if virtual keyword added in front of parent funtion then 4
    
    cout<<endl;

    //DownCasting     //virtual keyword
    child* o4 = (child*)new parent();    // parent constructor run-->object of parent and it doesnt inherit
    o4->add(x, y);                       //4     //if virtual keyword added in front of parent funtion then 16
    
    cout<<endl;


    
}


//======================================================================================================Abstraction
// implementation hiding
//Encapsulation is subset of Abstraction


//---------------------------------------------------------------------------------------------DYNAMIC MEMORY allocation

int a[100];    // memory given to stack

// and stack is small, heap is big

int a[10000000000];   // bad practice.......code might break

//                  thats why dynamic memoy allocation is goood

int* p = new int[100];   //good practice.....memory allocate in heap
delete []p;




// Creation of 2D array
int row= 5;
int col = 3;

int** arr =  new int *[row]; 

for(int i=0; i<rows; i++){
    arr[i] = new int[col];
}

for(int i=0; i<rows; i++){
    delete []arr[i];
}
delete []arr;

///-----------------------------------------------------------------------------------------IMPORTANT CONCEPT

//==========================================================================. const keyyword
//      0. compiler store const variable in read only memory, faster access time.
//      1. used to declare variable, function, object--->immutable, its like a promise we cant break;
Example-            const int x = 10;
                              x = 11;           //error

//      2. we can declase function as const. then we cant modify the state of the object  it is called on.
                ///method cant  chanege any of the memeber variable.

int fxn() const{

    x = 10  //error
}  





//==========================================================================. Initialisation list
//      Its nothing but writing a constructor in a new way.
//    In this we can even initialise const varibales.

class abc{
    int x;
    int *y;
    const int z;

    public:
    abc(int _x, int _y, int _z = 0){    //old way
        x = _x;
        y = new int(_y);
        z = _z;   // we cant initialise z here
    }

    abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z){ //new way
            // we can initialise z here
            //here we ccan write or leave it.
    }


}

//==========================================================================.MACROS
//      1. preprocessor darivatives
//      2. it doesnt take space , but replace value at preprocessing.

# define PI 3.13
# define MAX(x, y) (x>y?x:y)

//==========================================================================.Shallow vs Deep copy

// shallow copy--> assign same memory to the variable to which it is copied.

className obj1;

className obj2 = obj1;   // this will copy all variables with its memory location to obj2 variables.

// default constructor for shallow copy

class abc{
    int x;
    int *y;

    public:
    abc(int _x, int _y): x(_x), y(new int(_y)){}   //Initialisation list constructor

    abc(const class& obj){
        x = obj.x;
        y = obj.y;  //shallow copy
    }
}

abc o1(1,2);
abc o2 = o1;

//  Deep Copy---> it means we copy all the values but not memory locations which means new memory are made.

class abc{
    int x;
    int *y;

    public:
    abc(int _x, int _y): x(_x), y(new int(_y)){}   //Initialisation list constructor
    
    abc(const class& obj){
        x = obj.x;
        y = new int(*obj.y);  // deep copy  
    }
}

abc o1(1,2);
abc o2 = o1;

//--------------------------------------------------------------------------------------Global/Local Varibales

int x = 1;

int main(){

    x = 4;              //global variable
    int x = 2;          // local to main function

    cout << x << endl;      //2 local to main
    cout << ::x << endl;    //4 global

    {
        int x = 3;
        cout << x << endl;      //3 local to bracket
        cout << ::x << endl;   // 4 global
    }

    return 0;
}

//--------------------------------------------------------------------------------------Static Keyword

static data member : that variables is going to share memory with all the class objects.
static member functon :  there is no object of that class being passed into that method.
                         variable under static method should be static too.

no this pointer is passed when we make it static.


//-------------------------------------------------------------------------------------ABstraction in cpp

//  1. delivering only essential infromation to the outer world while masking the background details.
//  2. It is design and programming method that separates the interface from the implementation.
//  3. real life e.g verious fxnality of airpods but we dont know actual implementaion/working.
//      to driver car u need to know driving process , not machine of car engine.

//   abstraction in header files
//  abstraction using class, access modifier

//-----------------abstract class(important concept)

class that contain atleast one pure VIRTUAL FUNCTION, and this classes cannot be instantiated(means cant make object of it)
now this class become interface to outside world.


abstraction divide code into 2 category: interface and implementation


//-----------------------------------------------------------------------------------------------Inline FXN

1.  It is regular fxn defined by inline keyword.
2.  code for inline fxn is inserted directly into code of calling fxn by complier while compiing.
    which can result in faster execution
    less overhead compare to regular fxn calls.

3.  Instead of callling fxn, the statements of functions are pasted in calling function.
4.  used with small size fxn. 

inline void fxnName(){   //just add inline in front of fxn.

    //normal code
}

//-----------------------------------------------------------------------------------------------friend Keyword

1. not so usedful, but might be asked in interview.
2. It is used to share the information of class the was previousy hidden.
3. Ex- private member of class are hidden from every other class and can not be modified except getter and setter fxn.
4. similarly protected member are hidden from all the class other then child classes.
5. friend class : now class B can access private member of class 
    inside class A we need to mention that : friend class B;

6. friend function: a simple fxn can acess private member of class by becomeing its friend
    inside class A write : friend return_Type fxnName(arg_type);

//----------------------------------------------------------------------------------private constructor
0. Singleton class concept : use private constructor 
0_. constructor c++ microsoft : read this article.

1. private constructor can be created yes
2. but we can not call it direcly by creating object.
3. only a friend class can initialise the object and call private constructor

//-------------------------------------------------------Virtual Constructor & Destructor































// ---------------------------------------------------------------------------------------------------------LINK LIST
class Node{
    int data;
    Node* next;
};

Node* newNode =new Node();

//-------------------------------------------------------------virtual keyword

1.  Its a way to achieve RUN time Polymorphism
2.  VTables
    a. Formed for every class having atleast one virtual function and for its derived classes.
    b. It is static arrays, hence one instance for a class.
    c. Vptr(a hidden member pointer) is added by compiler to classes with virtual and its derived classes.
    d. Depending upon the object type Vptr is bounded to a VTable.
3. VTables are created at compile time.
4. when object of a particular type is created at runtime. 
There will be a VPtr  which will be initialised to point to a static VTable at the time of construction.

5. constructor cant be virtual
6 . destructor can be virtual..make base class destructor virtual.