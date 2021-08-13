#include <iostream>

int main(){

    std::cout << "Type the velocity in Km/h: ";
    int K;
    std::cin >> K;
    int M = K/3.6;
    std::cout << "The velocity in m/s is: " << M << std::endl; 

    return 0;
}
