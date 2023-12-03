#include <iostream>
using namespace std;
#include <math.h>




int BinaryToDecimalDivisionMethod(int number){
    int digitCount = 0 ;
    int binaryValue = 0 ;

    while(number/10){
        binaryValue = (pow(2,digitCount) * (number%10)) + binaryValue; 
       // cout << "bINARY VALUE : " << binaryValue << "---" << pow(10,digitCount) << endl;
        digitCount++;
        number = number/10;
    }
    binaryValue = (pow(2,digitCount) * (number%10)) + binaryValue; 
    //cout << "bINARY VALUE : " << binaryValue << "---" << pow(10,digitCount) << endl;
    return binaryValue;
}

int main(){

    cout << "Find binary of : ";
    int num;
    cin >> num;


   int binaryNumBM =  BinaryToDecimalDivisionMethod(num);
    cout << num << " decimal value is : " << binaryNumBM << endl;

    return 0;
}