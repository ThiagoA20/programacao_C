#include <iostream>

int main () {

    // Numerical types
    std::cout << "bytes len (Short): " << sizeof(short) << std::endl;
    std::cout << "bytes len (Int): " << sizeof(int) << std::endl;
    std::cout << "bytes len (Float): " << sizeof(float) << std::endl;
    std::cout << "bytes len (Double): " << sizeof(double) << std::endl;
    std::cout << "bytes len (Long): " << sizeof(long) << std::endl;
    std::cout << "bytes len (Long Long): " << sizeof(long long) << std::endl;

    // String --> collection of caracters
    std::string s = "hello World";
    std::cout << s << std::endl;
    // single characters string (one quote) --> char
    char t = 'a';
    std::cout << t << std::endl;

    // Bool
    bool varbool; //bool -----> true or false
    varbool = false;

    char varchar[] = "teste123"; //char -----> this type is declared as char[] or char[x] if you don't specify the number it will be defined automatically.

    // input

    int x;
    std::cout << "Input number: ";
    std::cin >> x;
    std::cout << "Your number is: " << x << std::endl;


    return 0;
}

