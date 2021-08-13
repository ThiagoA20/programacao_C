#include <iostream>
#include <math.h>

int main(){
    printf("Type a number: ");
    int x;
    
    std::cin >> x;

    if (x > 0) {
        std::cout << x << " is positive, it's square root is: " << sqrt(x) << std::endl;
    } else {
        std::cout << x << " is negative, it's square is: " << x * x << std::endl;
    };

    return 0;
}