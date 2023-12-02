#include <iostream>
using namespace std;

float circleArea(int radius){

    return 3.14*radius*radius;
}

int main(){

    int r;

    cout << "Enter Radius : ";
    cin >> r;

    float area = circleArea(r);

    cout << "Circle Area : " << area;
    return 0;
}