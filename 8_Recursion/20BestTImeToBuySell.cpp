#include<iostream>
#include<vector>

using namespace std;

void functionx(vector<int>& prices,int i,int& maxProfit){
        int j=i;
        while(j<prices.size()){
            int profit = prices[j] - prices[i];
             cout<<"j:"<<prices[j]<<"   i:"<<prices[i]<<"    profit:"<<profit<<endl;
            if(profit > maxProfit){
                maxProfit = profit;
            }
            j++;
        }
    }


int main(){

    vector<int> prices{7,1,5,3,6,4};

    int maxProfit = -1;
    for(int i=0; i<prices.size(); i++){
        functionx(prices,i,maxProfit);
    }

    cout << "value :"<<maxProfit<<endl;
    return 0;
}