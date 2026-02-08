#include <iostream>

class	Entity
{
	public:
		float x, y;
		Entity () : x(0.0f), y(0.0f) {}
		Entity (float X, float Y) : x(X), y(Y) {}
		~Entity () {}
		void	Move(float xa, float ya)
		{
			x += xa;
			y += ya;
		}
};

class	Player : public Entity
{
	public:
		const char *name;
		Player (): name("player") {}
		Player (const char *n) : name(n) {}
		~Player () {}
		void	PrintName()
		{
			std::cout<<name<<std::endl;
		}
		void	PrintPosition()
		{
			std::cout<<x<<" ; "<<y<<std::endl;
		}
};

int	main()
{
	Entity e(5.0, 6.3);
	Player p("poji");
	p.PrintName();
	p.PrintPosition();
	p.Move(2, 3);
	p.PrintName();
	p.PrintPosition();
	return (0);
}