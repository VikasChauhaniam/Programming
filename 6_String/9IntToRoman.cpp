#include<iostream>

using namespace std;

int main(){

    int num;

    cout << "Enter ur number : ";
    cin >> num;

    string romanNum;

    while(num>0){

        if(num>=1000){
            num -= 1000;
            romanNum.push_back('M');
        }
        else if(num>=900){
                num -= 900;
                romanNum.push_back('C');
                romanNum.push_back('M');
        } 
        else if(num>=500){
                num -= 500;
                romanNum.push_back('D'); 
        }
        else if(num>=400){
                num -=400;
                romanNum.push_back('C');
                romanNum.push_back('D');
        }
        else if(num>=100){
                num -= 100;
                romanNum.push_back('C');
        }
        else if(num>=90){
                num -=90;
                romanNum.push_back('X');
                romanNum.push_back('C');
        }
        else if(num>=50){
                num -= 50;
                  romanNum.push_back('L');
        }
        else if(num>=40){
                num -=40;
                romanNum.push_back('X');
                romanNum.push_back('L');
        }
        else if(num>=10){
                num -= 10;
                romanNum.push_back('X');
        }
        else if(num>=9){
                num -=9;
                romanNum.push_back('I');
                romanNum.push_back('X');
        }
        else if(num>=5){
                num -= 5;
                romanNum.push_back('V');
        }
        else if(num>=4){
                num -= 4;
                romanNum.push_back('I');
                romanNum.push_back('V');
            }
       else  if(num>=1){
                num -= 1;
                romanNum.push_back('I');
        }
    }

    cout << romanNum;
    return 0;
}