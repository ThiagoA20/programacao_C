#include <iostream>

int main(){

    int temperatureCelcius;
    std::cout << "Type a temperature in celcius: ";
    std::cin >> temperatureCelcius;
    int temperatureFareheint = temperatureCelcius * (9/5) + 32;
    std::cout << "The temperature in fareheint is: " << temperatureFareheint << std::endl;

    return 0;
}