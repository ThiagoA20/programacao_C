#include <iostream>

int main(){
    std::cout << "Type your income: ";
    int income;
    std::cin >> income;
    std::cout << "Type your loan: ";
    int loan;
    std::cin >> loan;

    float grant = income - ((income/100) * 80);

    if (loan > grant){
        std::cout << "The loan was denied! :(" << std::endl;
    } else {
        std::cout << "The loan was accepted! :)" << std::endl;
    }
    return 0;
}