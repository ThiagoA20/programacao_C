#include <iostream>

int main() {

    int x;
    int y;
    std::cout << "Type the first number: ";
    std::cin >> x;
    std::cout << "Type the first number: ";
    std::cin >> y;
    int z;
    if (x > y) {
        z = x;
    } else {
        z = y;
    };
    std::cout << "The biggest number is: " << z << std::endl;

    return 0;
}