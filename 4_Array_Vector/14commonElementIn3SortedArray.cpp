#include <iostream>
#include <vector>


using namespace std;

 vector<int> commonInThree(vector<int> n1, vector<int> n2, vector<int> n3){
    vector<int> common;
   // vector<int> common2;

    int i=0;
    int j=0;
    int k=0;
    
    int iteration = 0;
    //int match = 0;
    //cout << "commonSize:"<<common.size()<<endl;
    while(i<n1.size() && j<n2.size() && k<n3.size()){
        iteration++;
        if((n1[i] == n2[j]) && ( n2[j] == n3[k])){
            common.push_back(n1[i]);
            i++;
            j++;
            k++;
            //match++;
        }
        else if(n1[i] < n2[j]){
            i++;
        }
        else if(n2[j] < n3[k]){
            j++;
        }
        else{
            k++;
        }

        cout << "iteration : "<< iteration << " || n1-->" <<n1[i]<< " || n2-->" <<n2[j]<< " || n3-->" <<n3[k]<<endl;
    }



    return common;
}

void printfxn(vector<int> a){

    for(int i : a){
        cout << i << "  ";
    }

}

int main(){

    vector<int> n1{1, 5, 10, 20, 40, 80};
    vector<int> n2{6, 7, 20, 80, 100};
    vector<int> n3{3, 4, 15, 20, 30, 70, 80, 120};

  //  cout << "1" << endl;
   vector<int> common =  commonInThree(n1, n2, n3); 
  // cout << "2" << endl;
   cout << "commonSize:"<<common.size()<<endl;



//cout << "3" << endl;
    printfxn(common);

    return 0;

}    