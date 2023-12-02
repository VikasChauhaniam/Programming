#include <iostream>
#include <math.h>

using namespace std;

string isPrime(int number){
    
    for(int i= 2; i<= sqrt(number); i++){
        if(number%i == 0){
            return "Not Prime";
        }
    }
    return "Prime";

}

int main(){

    int num;
    cout << "Enter the number : ";
    cin >> num;

    string numPrime = isPrime(num);

    cout << num << " Factorial is " <<  numPrime;

    return 0;
}