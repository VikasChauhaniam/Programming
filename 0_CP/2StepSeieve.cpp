#include<iostream>
#include<vector>

using namespace std;


bool isPrime(int i){
    
    //method 2
   //for(int divisor =2; divisor*divisor<=i; divisor++){
   for(int divisor =2; divisor<i; divisor++){

        if(i%divisor == 0)
        return false;
    }
    return true;

}


vector<bool> step_Sieve_Method_2(int l, int r){

    vector<bool> prime(r-l+1, true);

    vector<int> primenum;

    for(int i=2; i*i<=r; i++){
       // cout<<"trying :"<<i<<endl;
        if(isPrime(i)){
         //   cout<<"inserted :"<<i<<endl;
            primenum.push_back(i);

            int firstNum = (l/i)*i;
            if(firstNum<l){
                firstNum +=i;
            }
            while(firstNum <= r){
                prime[firstNum - l] = false;
                firstNum += i;
            }

        }
    }
    return prime;
}

int main(){

    int l, r;

    cout<< "enter value of l & r in which u wanna find prine : ";

    


    cin >> l>>r;
  

    vector<bool> prime = step_Sieve_Method_2(l, r);

    for(int val=0; val<prime.size(); val++){
        if(prime[val]){
            cout << l+val << " ";
       }
    }

    return 0;
}
