// C++ supports object-oriented programming
// Class is a way to group data and functionality
#include <iostream>
#define Log(x) std::cout << x << std::endl;

class Player {
public: // by default class has private visibility, public allows to access varibales/methods outside the class
	int x, y;
	int speed;

	void M_Move(int dx, int dy) { 
		x += dx * speed;
		y += dy * speed;
	}
}; // need to add semi-colon at the end

// struct vs. class
// default visibility of struct is public, class is private
// inheritance is usually preferred to class, not struct
// struct is very similar to class, it exists mainly due to compatibability of C language (which only had struct but not class)
// struct is preferred over class when just grouping variables (it just not much functionality that class supports)
struct s_Player { 
	int x, y;
	int speed;

	void M_Move(int dx, int dy) {
		x += dx * speed;
		y += dy * speed;
	}
};

void Move(Player& player, int dx, int dy) { // pass-by-reference whenever passing the object/class!
	player.x += dx * player.speed;
	player.y += dy * player.speed;
}

int main() {
	int positionX, positionY; double playerSpeed = 2; // list of variables of players - how can we group them?
	Player player; // instantiate player object
	player.x = 5; player.y = 10; player.speed = 0.1; // if member variables are private, this should give an error

	Move(player, 5, -7); // can define Move function to manipulate player's variable
	player.M_Move(5, -7); // better approach: define member function in the class, we don't need to pass large-size object every time & cleaner code

	s_Player s_player; // struct instantiation
	s_player.x = 10; // default visibility of struct is public

	std::cin.get();
}