#include <iostream>

int main(){

    std::cout << "Type a number: ";
    int x;
    std::cin >> x;
    x = x / 5;
    std::cout << "Number dividided by 5: " << x << std::endl;
    return 0;
}