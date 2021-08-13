#include <iostream>

int main(){
    std::cout << "Type the first number: ";
    int x;
    std::cin >> x;
    std::cout << "Type the second number: ";
    int y;
    std::cin >> y;
    if (x > y){
        std::cout << "The biggest number is: " << x << std::endl;
    } else if (x == y) {
        std::cout << "The two numbers are equal" << std::endl;
    } else {
        std::cout << "The biggest number is: " << y << std::endl;
    }
    
    return 0;
}