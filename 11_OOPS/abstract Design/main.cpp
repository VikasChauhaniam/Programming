#include<iostream>
#include "bird.h"
using namespace std;

void birddoTask(Bird *&bird){

    bird->eat();
    bird->fly();

}


int main(){

    Bird *bird = new Sparrow();

    birddoTask(bird);
    return 0;
}