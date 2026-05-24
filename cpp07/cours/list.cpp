#include <iostream>
#include <string>

template <typename T> //template definition
class List {
    public:
        List<T>() {} //default constructor
        List<T>(T const & content) { //constructor
            this->_content = content;
        }
        List<T>(List<T> const & src) { //copy constructor
            this->_content = src._content;
        }
        ~List<T>() {} //destructor
        List<T> & operator=(List<T> const & src) { //assignment operator
            this->_content = src._content;
            return *this;  
        }
        T const & getContent() const { //getter
            return this->_content;
        }
    private:
        T           _content;
        List<T>     *_next;
};

int main (void)
{
    List<int> a(42);
    List<float> b(42.21f);
    List<char> c('c');
    List<List<int>> d(a);
    std::cout << "List a content : " << a.getContent() << std::endl;
    std::cout << "List b content : " << b.getContent() << std::endl;
    std::cout << "List c content : " << c.getContent() << std::endl;
    std::cout << "List d content : " << d.getContent().getContent() << std::endl;
    return 0;
}