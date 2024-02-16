#include<iostream>
using namespace std;

#include<stack>

//function to put 1 element at correct position
void myFxn(stack<int> &s, int topElement){
    //base
    if(s.empty()){
        s.push(topElement);
        return;
    }

    //solve 1 case;
    int temp = s.top();
    if(temp > topElement){
        s.pop();

        //recursion
        myFxn(s, topElement);
        s.push(temp);
    }
    else{
        s.push(topElement);
    } 
}

void print(stack<int> &s){
    if(s.empty()){
        return;
    }

    cout << s.top() << " ";
    int temp = s.top();

    s.pop();

    print(s);

    s.push(temp);
}

void sortit(stack<int> &s){
    //baseacase
    if(s.empty()){

        return;
    }

    //solve 1 case
    int topElement = s.top();
    s.pop();

    //reverse whole remaining stack
    sortit(s);

    //put the choose top element at bootom;
    myFxn(s, topElement);

}
int main(){

    stack<int> s;

    s.push(21);
    s.push(2);
    s.push(13);
    s.push(41);
    s.push(5);
    s.push(6);

    print(s);cout<<endl;
    
    //save topmost element

    sortit(s);

    print(s);cout<<endl;
    
    
    
    
    

    

    return 0;
}