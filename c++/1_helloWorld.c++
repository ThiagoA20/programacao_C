// Import the library to control the input/output of the program
#include <iostream>

/*
the main function is a entry point for the program,
in other languages like python, it's not necessary as it is interpreted,
but in C++ you need to specify the main function.
*/
int main() {

    /* in the iostream we have namespaces, one of them is std,
    and to access the cout function we need to add two collons,
    then to pass the 'Hello World!' text as a parameter, it's
    necessary to add the << signal, and finally the << std::endl
    to show where is the end*/
    std::cout << "Hello World!" << std::endl;
    
    // return 0 means that the program execute sucessfully
    return 0;
}

/*
the way that the parameters are passed to thet cout function
looks like a HTML tag.
*/