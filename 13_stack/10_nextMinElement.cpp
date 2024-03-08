#include<iostream>
using namespace std;

#include<vector>
#include<stack>

int main(){

    vector<int> givenArray = {2, 1, 4, 3};
    vector<int> minArray(4); 

   // method 1--------------------------------------------------
    stack<int> st;
    st.push(-1);

    for(int i=givenArray.size()-1; i>=0; i--){

        if(givenArray[i] > st.top()){
            minArray[i] = st.top();
            st.push(givenArray[i]);
        }
        else{
            st.pop();
            i++;
        }
    }

    


    for(int i=0; i<givenArray.size(); i++){
        cout <<givenArray[i]<<" ";
    }cout<<endl;

    for(int i=0; i<givenArray.size(); i++){
        cout <<minArray[i]<<" ";
    }cout<<endl;




    return 0;
}