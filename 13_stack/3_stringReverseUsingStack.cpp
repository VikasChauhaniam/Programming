#include<iostream>
using namespace std;
#include<stack>

int main(){

    string s = "vikas Chauhan";

    stack<char> st;


    cout<< "before operation : " << s<<endl;

    for(int i = 0; i<s.size(); i++){
        st.push(s[i]);
    }

    for(int i = 0; i<s.size(); i++){
        s[i] = st.top();
        st.pop();
    }

    cout<< "after operation : " << s<<endl;

    return 0;
}