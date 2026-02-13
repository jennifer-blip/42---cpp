# pragma once
#include <iostream>
#include <string>


class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string Name) : _name(Name)
        {
            std::cout<<this->_name<<" is born"<<std::endl;
        }
        ~Zombie()
        {
            std::cout<<this->_name<<" died"<<std::endl;
        }
        void    announce(void);
        std::string getName(){return(_name);};
        
};

Zombie*     newZombie( std::string name );
void        randomChump( std::string name );
void        announce(Zombie* z);