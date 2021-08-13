#include <iostream>

int main(){
    std::cout << "Type a number: ";
    int x;
    std::cin >> x;
    if (x%2){
        std::cout << "The number " << x << " is odd" << std::endl;
    } else {
        std::cout << "The number " << x << " is pair" << std::endl;
    }
    return 0;
}