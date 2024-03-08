#include<iostream>
using namespace std;

#include<vector>
#include<stack>


vector<int> findPreviousMinimum(vector<int> &givenArray){
    vector<int> minArray(givenArray.size());
    stack<int> st;
    st.push(-1);

    for(int i=0; i<givenArray.size(); i++){

        //put answer inside stack
        while(st.top() != -1 && givenArray[st.top()] >= givenArray[i]){
            st.pop();
        }

        //smallest element found
        minArray[i] = st.top();

        //push index into stack
        st.push(i);

    }
    return minArray;
}

vector<int> findNextMinimum(vector<int> &givenArray){

    vector<int> minArray(givenArray.size());
    stack<int> st;
    st.push(-1);

    for(int i=givenArray.size()-1; i>=0; i--){

        //put answer inside stack
        while(st.top() != -1 && givenArray[st.top()] >= givenArray[i]){
            st.pop();
        }

        //smallest element found
        
        minArray[i] = st.top();
        
        

        //push index into stack
        st.push(i);


    }
    return minArray;

    
}

void printArray(vector<int> &Array){

    for(int i=0; i<Array.size(); i++){
        cout <<Array[i]<<" ";
    }cout<<endl;
}

int main(){

    vector<int> givenArray = {2,1,5,6,2,3};


   vector<int> prevMinArray = findPreviousMinimum(givenArray);
   vector<int> nextMinArray = findNextMinimum(givenArray);
  

    printArray(givenArray);
    printArray(prevMinArray);
    printArray(nextMinArray);

    int maxArea = 0;

    for(int i=0; i<givenArray.size(); i++){
        int length = givenArray[i];

        if(nextMinArray[i] == -1){
            nextMinArray[i] = 6;
        }
        int breath = nextMinArray[i] - prevMinArray[i] - 1;

        int area = length * breath;

        maxArea = max(maxArea, area);
        cout << maxArea<<endl;
    }

        return maxArea;


    return 0;
}