#include <iostream>
#include <iomanip>
#include <string>

template< typename T = float> //default template parameter, if no type is specified, T will be float
class Vertex {
    public :
    Vertex (T const & x, T const & y, T const & z) : _x(x), _y(y), _z(z) {}
    ~Vertex() {}

    T const & getx(void) const { return this->_x; }
    T const & gety(void) const { return this->_y; }
    T const & getz(void) const { return this->_z; }

    //etc
    private :
    T const _x;
    T const _y;
    T const _z;    

    Vertex(void); //default constructor is private, we don't want to create a vertex without specifying the coordinates
};

template< typename T>
std::ostream & operator<<(std::ostream& os, Vertex<T> const & v) //this is the template of an operator overload, it will be instantiated for each type of vertex we create
{
    std::cout.precision(1);
    os << std::setiosflags(std::ios::fixed);
    os << "Vertex(" << v.getx() << ", " << v.gety() << ", " << v.getz() << ")";
    return os;
}

int main (void)
{
    Vertex<int> v1(12, 23, 34);
    Vertex<> v2(12, 23, 34);

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return 0;
}