#include<iostream>

using namespace std;

void reverseRec(string& line,int s,int e){

    if(s>=e){
       return;
    }

    swap(line[s],line[e]);

    reverseRec(line, s+1, e-1);

}

int main(){

    string line = "a";
    int s =0;
    int e = line.size()-1;

    cout << line<<endl; 

    reverseRec(line, s, e);

    cout << line;
    return 0;
}