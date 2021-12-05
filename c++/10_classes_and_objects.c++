#include <iostream>
#include <string>
using namespace std;

class Car {

    // public attributes/methods can be accessed outside of the class
    public:
        string brand;
        int max_velocity;
        string color;
        int year;
        bool new_car;
};

int main() {
    Car myNewCar;

    myNewCar.brand = "volksvagem";
    myNewCar.max_velocity = 299;
    myNewCar.color = "blue";
    myNewCar.year = 1998;
    myNewCar.new_car = true;

    cout << myNewCar.brand << '\n' << myNewCar.max_velocity << '\n' << myNewCar.color << '\n' << myNewCar.year << '\n' << myNewCar.new_car << endl;

    return 0;
}