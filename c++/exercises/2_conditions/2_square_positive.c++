#include <iostream>

int main(){

    std::cout << "Type a number: ";
    int x;
    std::cin >> x;

    if (x > 0){
        std::cout << "The square of " << x << " is: " << x * x << std::endl;
    } else {
        std::cout << "Error! the number '" << x << "' is not valid!" << std::endl;
    }

    return 0;
}