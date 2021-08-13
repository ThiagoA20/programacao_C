#include <iostream>

int main(){
    int number;

    std::cout << "Type a number: ";
    std::cin >> number;
    number = number * number;
    std::cout << "Square number: " << number << std::endl;
    return 0;
}