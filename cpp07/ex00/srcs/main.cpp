#include <iostream>
#include <string>
#include "../includes/template.tpp"
#include "../includes/display.hpp"

int main(void)
{
    
    display("////////TESTING TEMPLATE FUNCTIONS WITH INT", BROWN); 
    int a = 21;
    int b = 42;
    display("original values : a = " + std::to_string(a) + ", b = " + std::to_string(b), GREEN);
    display("TESTING MAX FUNCTION:max(a, b) = " + std::to_string(max<int>(a, b)), BLUE); //explicit instanciation
    display("TESTING MIN FUNCTION:min(a, b) = " + std::to_string(min<int>(a, b)), BLUE); //explicit instanciation
    display("TESTING SWAP FUNCTION: swapping a and b", BLUE);
    swap<int>(a, b);
    display("TESTING SWAP FUNCTION: swapping a = " + std::to_string(a) + " and b =" + std::to_string(b), BLUE);

    display("////////TESTING TEMPLATE FUNCTIONS WITH FLOAT", BROWN); 
    float c = 21.42f;
    float d = 42.21f;
    display("original values : c = " + std::to_string(c) + ", d = " + std::to_string(d), GREEN);
    display("TESTING MAX FUNCTION:max(c, d) = " + std::to_string(max<float>(c, d)), BLUE); //explicit instanciation
    display("TESTING MIN FUNCTION:min(c, d) = " + std::to_string(min<float>(c, d)), BLUE); //explicit instanciation
    swap<float>(c, d);
    display("TESTING SWAP FUNCTION: swapping c = " + std::to_string(c) + " and d = " + std::to_string(d), BLUE);

    display("////////TESTING TEMPLATE FUNCTIONS WITH CHAR", BROWN); 
    char e = 'e';
    char f = 'f';
    display("original values : e = " + std::string(1, e) + ", f = " + std::string(1, f), GREEN);
    display("TESTING MAX FUNCTION:max(e, f) = " + std::string(1, max<char>(e, f)), BLUE); //explicit instanciation
    display("TESTING MIN FUNCTION:min(e, f) = " + std::string(1, min<char>(e, f)), BLUE); //explicit instanciation
    swap<char>(e, f);
    display("TESTING SWAP FUNCTION: swapping, e = " + std::string(1, e) + " and f = " + std::string(1, f), BLUE);
    return 0;
}
