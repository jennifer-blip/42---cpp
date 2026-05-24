#include <iostream>
#include <string>

template <typename T> //template definition

T const & max(T const & x, T const & y) {
    return (x>=y ? x: y);
}

int foo(int x){
    std::cout << "long computing time" << std::endl;
    return x;
}

int main(void)
{
    int a = 21;
    int b = 42;

    std::cout << "max(a, b) = " << max<int>(a, b) << std::endl; //explicit inxtanciation
    std::cout << "max(a, b) = " << max(a, b) << std::endl; //implicit instanciation

    float c = 21.42f;
    float d = 42.21f;
    std::cout << "max(c, d) = " << max<float>(c, d) << std::endl; //explicit inxtanciation
    std::cout << "max(c, d) = " << max(c, d) << std::endl; //implicit instanciation

    char e = 'e';
    char f = 'f';
    std::cout << "max(e, f) = " << max<char>(e, f) << std::endl; //explicit inxtanciation
    std::cout << "max(e, f) = " << max(e, f) << std::endl; //implicit instanciation

    int ret = max<int>(foo(a), foo(b)); //explicit inxtanciation
    std::cout << "Max of " << a << " and " << b << " is " << ret << std::endl;
    return 0;
}