#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "FInd Square root of :";
    cin >> n;
    cout << endl;

    int precision;
    cout << "precision : ";
    cin >> precision;
    cout << endl;

    int start = 0;
    int end = n;
    int mid = (start+end)/2;

    int ans=0;

    while(start<end){

        if(mid*mid == n){
            ans = mid;
            break;
        }
        else if(mid*mid > n){
            end = mid - 1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
        mid = (start + end)/2;
    }
    
    double FinalAns = ans;
    double stepSize = 0.1;
    for(int i=0; i<precision; i++){

        for(double j=FinalAns; j*j<=n; j=j+stepSize){
            FinalAns = j;
        }

        stepSize = stepSize/10;
    }
    cout << "ans is : "<< FinalAns;
}