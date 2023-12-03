#include <iostream>
using namespace std;
#include <math.h>


int decimailToBinaryDivisionMethod(int number){
    int digitCount = 0 ;
    int binaryValue = 0 ;

    while(number/2){
        binaryValue = (pow(10,digitCount) * (number%2)) + binaryValue; 
       // cout << "bINARY VALUE : " << binaryValue << "---" << pow(10,digitCount) << endl;
        digitCount++;
        number = number/2;
    }
    binaryValue = (pow(10,digitCount) * (number%2)) + binaryValue; 
    //cout << "bINARY VALUE : " << binaryValue << "---" << pow(10,digitCount) << endl;
    return binaryValue;
}

int decimailToBinaryBitMethod(int number){
    int binaryNum=0;
    int bit = 0;
    int count = 0;
    while(number){
        int bit =  (number & 1);
        binaryNum = (bit*pow(10,count)) + binaryNum;
        number = number >> 1; 
        count++;
    }
    return binaryNum;
}

int main(){

    cout << "Find decimal of : ";
    int num;
    cin >> num;

   int binaryNumDM =  decimailToBinaryDivisionMethod(num);
   cout << num << " binary value is : " << binaryNumDM << endl;

   int binaryNumBM =  decimailToBinaryBitMethod(num);
    cout << num << " binary value is : " << binaryNumBM << endl;

    return 0;
}