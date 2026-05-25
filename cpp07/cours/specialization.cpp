#include <iostream>
#include <string>

template<typename T, typename U>
class Pair {
    public :
    Pair<T, U>(T const & lhs, U const & rhs): _lhs(lhs), _rhs(rhs){
        std::cout << "Generic template" << std::endl;
        return;
    }
    ~Pair<T, U>(void) {}
    T const & getlhs(void) const { return this->_lhs; }
    U const & getrhs(void) const { return this->_rhs; }
    private :
    T const _lhs;
    U const _rhs;
    Pair<T, U>(void); //default constructor is private, we don't want to create a pair without specifying the values
};

//partial specialization of the Pair template for the case where both types are the same
template <typename U>
class Pair<int, U> {
    public :
    Pair<int, U>(int const & lhs, U const & rhs): _lhs(lhs), _rhs(rhs){
        std::cout << "Int partial specialization" << std::endl;
        return;
    }
    ~Pair<int, U>(void) {}
    int const & getlhs(void) const { return this->_lhs; }
    U const & getrhs(void) const { return this->_rhs; }
    private :
    int const _lhs;
    U const _rhs;
    Pair<int, U>(void); //default constructor is private, we don't want to create a pair without specifying the values
};

//full specialization of the Pair template for the case where both types are int
template<>
class Pair<bool, bool> {
    public :
    Pair<bool, bool>(bool lhs, bool rhs){
        std::cout << "Bool/bool specialization" << std::endl;
        this->_m = 0;
        this->_m |= static_cast<int>(lhs) << 0;
        this->_m |= static_cast<int>(rhs) << 1;
        return;
    }
    ~Pair<bool, bool>(void) {}
    bool fst(void) const { return this->_m & 0x01; }
    bool snd(void) const { return this->_m & 0x02; }
    private :
    int _m;
    Pair<bool, bool>(void); //default constructor is private, we don't want to create a pair without specifying the values
};

template<typename T, typename U>
std::ostream & operator<<(std::ostream& os, Pair<T, U> const & p) //this is the template of an operator overload, it will be instantiated for each type of pair we create
{
    os << "Pair(" << p.getlhs() << ", " << p.getrhs() << ")";
    return os;
}

std::ostream& operator<< (std::ostream& os, Pair<bool, bool> const & p) //this is the operator overload for the full specialization of the Pair template for the case where both types are bool
{
    os << "Pair(" << p.fst() << ", " << p.snd() << ")";
    return os;
}

int main(void)
{
    Pair<int, float> a(42, 42.21f);
    Pair<std::string, float> b("Hello", 42.21f);
    Pair<float, bool> c(42.21f, true);
    Pair<int, int> d(42, 21);
    Pair<bool, bool> e(true, false);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << e << std::endl;

    return 0;
}
