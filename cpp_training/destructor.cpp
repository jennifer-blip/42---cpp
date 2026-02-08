#include <iostream>

class Entity
{
	public:
		float x, y;
		Entity (): x(0.0f), y(0.0f) {std::cout<<"data initialized"<<std::endl;}
		~Entity ()
		{
			std::cout<<"data destroyed"<<std::endl;
		}
		void Print()
		{
			std::cout<<x<<" ; "<<y<<std::endl;
		}
};

void	Fonction()
{
	Entity e;
	e.Print();
}

int	main()
{
	Fonction();
	std::cin.get();
}