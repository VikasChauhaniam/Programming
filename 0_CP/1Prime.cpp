#include<iostream>
#include<vector>

using namespace std;


bool isPrime(int i){
    
    //method 2
    for(int divisor =2; divisor*divisor<=i; divisor++){
    //for(int divisor =2; divisor<i; divisor++){

        if(i%divisor == 0)
        return false;
    }
    return true;

}

vector<bool> Method_1(int r){

    vector<bool> prime(r+1,false);

   // prime[0] = prime[1] = false;

    for(int i=2; i<=r; i++){
       prime[i] =  isPrime(i) ? true : false;
    }

    return prime;

}

vector<bool> Sieve_Method_2(int r){

    vector<bool> prime(r+1,true);
    prime[0] = prime[1] = false;
    //optimisation2
    for(int i=2; i*i<=r; i++){
    //for(int i=2; i<=r; i++){
       if(isPrime(i)){
            prime[i] = true;
            int j = i*i;    //optimisation
            while(j<=r){
                prime[j] = false;
                j = j+i;
            }
       }
    }

    return prime;
}

int main(){

    int l, r;

    cout<< "enter value of l & r in which u wanna find prine : ";

    
//   cin >> r; 

//   bool x = isPrime(r);

//     if(x){
//         cout << "prine";
//     }
//     else{
//         cout <<"not prime";
//     }



    cin >> l>>r;
    //vector<bool> prime = Method_1(r);

    vector<bool> prime = Sieve_Method_2(r);
    for(int val=2; val<prime.size(); val++){
        if(prime[val]){
            cout << val << " ";
        }
    }

    return 0;
}
