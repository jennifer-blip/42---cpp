#include "Zombie.hpp"

int main(void)
{
    Zombie moche("moche");
    Zombie* laid = newZombie("laid");
    moche.announce();
    announce(laid);
    delete (laid);
    return(0);
}
