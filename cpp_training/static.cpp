#include <iostream>

struct	Entity
{
	static int	x;
	static int	y;

	void print(void)
	{
		std::cout << x << " ; "<< y << std::endl;
	}
};

int	Entity::x;
int	Entity::y;

int	main(void)
{
	Entity	e;
	Entity	e1;

	e.x = 3;
	e.y = 4;
	e1.x = 6;
	e1.y = 7;

	e.print();
	e1.print();
	std::cin.get();
}