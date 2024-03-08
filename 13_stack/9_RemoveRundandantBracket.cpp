#include<iostream>
using namespace std;
#include<stack>

void solution(stack<char> &st,string s){

    for(int i = 0; i<s.length(); i++){

        if(s[i] == ')'){
            while(st.top() != '('){
                if(st.top() == '+'){
                    oprtr = true;
                }
            }
        }       
    }

}

int main(){

    string s = "((a+b))";

    stack<char> st;

    bool isRedundantExist = solution(st, s);

    if(isRedundantExist){
        cout << "redundant exit" << endl;
    }
    else{
        cout << "its perfect" << endl;
    }

    return 0;
}