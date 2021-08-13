#include <iostream>

int main(){

    std::cout << "Temperature fareheint: ";
    int temperatureFareheint;
    std::cin >> temperatureFareheint;
    int temperatureCelcius = 5 * (temperatureFareheint - 32)/9;
    std::cout << "the temperature in Celcius is: " << temperatureCelcius << std::endl;

    return 0;
}