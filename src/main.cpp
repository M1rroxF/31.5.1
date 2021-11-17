#include <iostream>
#include "Toy.h"
#include "Dog.h"

using namespace std;
int main(){
    SharedPtrToy ball("ball");
    SharedPtrToy bone("bone");
    SharedPtrToy ball2;
    ball2 = ball;

    Dog mrFirz("Firz", &ball);
    Dog mrKruz("Kruz", &bone);

    mrKruz.loseToy();
}
