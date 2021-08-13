#include <iostream>

int main(){
    std::cout << "Type the first number: ";
    int x;
    std::cin >> x;
    std::cout << "Type the second number: ";
    int y;
    std::cin >> y;
    if (x > y){
        std::cout << "The number " << x << " is the biggest and the difference between " << x << " and " << y << " is " << x - y << std::endl;
    } else {
        std::cout << "The number " << y << " is the biggest and the difference between " << y << " and " << x << " is " << y - x << std::endl;
    }

    return 0;
}