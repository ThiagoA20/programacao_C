#include <iostream>

int main(){

    int x;
    int y;
    int z;

    std::cout << "Type the first number: ";
    std::cin >> x;
    std::cout << "Type the second number: ";
    std::cin >> y;
    std::cout << "Type the third number: ";
    std::cin >> z;

    int soma = x + y + z;

    std::cout << "the sum of the values " << x << " + " << y << " + " << z << " = " << soma << std::endl;

    return 0;
}