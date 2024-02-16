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
    s.pop();

    //recursion
    myFxn(s, topElement);

    //backtrack
    s.push(temp);
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
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(11);

    print(s);cout<<endl;
    
    //save topmost element
    int topElement = s.top();
    s.pop(); 
    cout << "Top elemt is : "<<topElement<<endl;
    myFxn(s, topElement);

    print(s);

    return 0;
}