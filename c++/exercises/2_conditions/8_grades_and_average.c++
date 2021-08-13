#include <iostream>

int main() {

    std::cout << "Type the first number: ";
    float n1;
    std::cin >> n1;
    std::cout << "Type the second number: ";
    float n2;
    std::cin >> n2;

    std::cout << "The average is: " << (n1 + n2)/2 << std::endl;

    return 0;
}