#include<iostream>

using namespace std;

void subSquence(string input, string output, int indx){

    if(indx >= input.length()){
        cout<< output<<endl;
        return;
    }

    //exclude
    subSquence(input, output, indx+1);

    //include
    output.push_back(input[indx]);
    subSquence(input, output, indx+1);

}

int main(){

    string input = "cd";
    string output = "";
    int indx = 0;

    subSquence(input, output, indx);
    return 0;
}