#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printfxn(vector<int> a){

    for(int i : a){
        cout << i << "  ";
    }

}

int main(){

    vector<int> val1{1, 2, 3, 4 , 5};
    vector<int> val2{9, 8, 7};

    vector<int> ans;

    int carry = 0;

    while((val1.size() > 0) && (val2.size() > 0)){
        int sum = val1.back() + val2.back() + carry;

        val1.pop_back();
        val2.pop_back();

        ans.push_back(sum%10);
        carry = sum/10;
    }
    while((val1.size() > 0)){
        int sum = val1.back() + carry;

        val1.pop_back();

        ans.push_back(sum%10);
        carry = sum/10;
    }
    while((val2.size() > 0)){
        int sum =  val2.back() + carry;

        val2.pop_back();

        ans.push_back(sum%10);
        carry = sum/10;
    }

    reverse(ans.begin(), ans.end());
    printfxn(ans);

    return 0;
}