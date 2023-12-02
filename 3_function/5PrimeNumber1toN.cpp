#include <iostream>
#include <math.h>

using namespace std;


bool isPrime(int number){
    
    if( number == 1 || number ==2)
        return true;
    

    for(int i= 2; i<= sqrt(number); i++){
        if(number%i == 0){
            return false;
        }
    }
    return true;

}

void primeNumbers(int number){
    
    for(int i=2; i<=number ; i++){
        if(isPrime(i)){
            cout << i << endl;
        }
    }

}

int main(){

    int num;
    cout << "Enter the number : ";
    cin >> num;

    primeNumbers(num);

    return 0;
}