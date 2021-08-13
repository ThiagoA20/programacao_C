#include <iostream>

int main(){

    std::cout << "Type the temperature in Celcius: ";
    int C;
    std::cin >> C;
    int K = C + 273;
    std::cout << "the temperature in Kelvin is: " << K << std::endl;

    return 0;
}
