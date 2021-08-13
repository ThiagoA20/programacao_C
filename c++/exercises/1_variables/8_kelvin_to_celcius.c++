#include <iostream>

int main(){

    std::cout << "Type the temperature in Kelvin: ";
    int K;
    std::cin >> K;
    int C = K - 273;
    std::cout << "the temperature in celcius is: " << C << std::endl;

    return 0;
}
