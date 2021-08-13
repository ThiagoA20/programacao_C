#include <iostream>
#include <math.h>

int main(){
    printf("Type a number: ");
    int x;
    std::cin >> x;
    if (x > 0){
        std::cout << "The square of " << x << " is: " << x * x << std::endl;
        std::cout << "The square root of " << x << " is: " << sqrt(x) << std::endl;
    } else {
        std::cout << "Error! The number needs to be positive." << std::endl;
    }
    return 0;
}