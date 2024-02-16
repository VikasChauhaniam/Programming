#include<iostream>
using namespace std;

#include<stack>

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

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(6);
    

    print(s);cout<<endl;
    
    //save topmost element
    int topElement = 1;
    //s.pop(); 
    myFxn(s, topElement);

    print(s);

    return 0;
}