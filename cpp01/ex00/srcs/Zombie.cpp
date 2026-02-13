#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout<<this->_name<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
}

void  announce(Zombie* z)
{
    std::cout<<z->getName()<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
}