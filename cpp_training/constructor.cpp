#include <iostream>

class Entity
{
	public :
		float x, y;
	Entity ()
	{
		x = 0.0f;
		y = 0.0f;
	}
	Entity (float X, float Y)
	{
		x = X;
		y = Y;
	}
	void	Print()
	{
		std::cout << x << " ; " << y << std::endl;
	}
};

// autre version pour resultat similaire

class Entity1
{
	public :
		float x, y;
		Entity1() : x(0.0f), y(0.0f) {}
		Entity1(float X, float Y) : x(X), y(Y) {}
		void	Print()
		{
			std::cout<<x<<" ; "<<y<<std::endl;
		}
};

int	main(void)
{
	Entity e0;
	Entity e1(10.0f, 5.0f);
	Entity1 e10;
	Entity1 e11(12.0f, 7.0f);
	e0.Print();
	e1.Print();
	e10.Print();
	e11.Print();
	return (0);
}