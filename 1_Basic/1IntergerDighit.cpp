#include <iostream>
using namespace std;

int main()
{
    char a = 'c';

    switch(a){
        case 1 : cout << "1";
        break;
        case 2 : cout << "2";
        break;
        case 'c' : cout << "3";
        break;
        default : cout << "default";
        
    }

    return 1;
}