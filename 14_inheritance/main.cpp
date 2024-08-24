// inheritance: created hierachy of classes, branching base class to subclasses
// avoids code duplication - subclasses share parent class functionalities
#include <iostream>
#define Log(x) std::cout << x << std::endl;

class Robot {
public: 
	int x = 0, y = 0;
	double speed = 0.1;

	void Move(int dx, int dy) {
		x += dx * speed;
		y += dy * speed;
	}
};

// NameRobot extends Robot class (Robot + extra functionalities with name)
class NameRobot : public Robot { // NameRobot is both Robot and NameRobot type - Polymorphism (having multiple types for single type)
public:	
	const char* Name;
	
	void PrintName() {
		std::cout << Name << std::endl;
	}
};

int main() {
	NameRobot nr;
	nr.Move(3, 4); // NameRobot object can call member functions from parent class - Robot

	std::cout << sizeof(Robot) << ", " << sizeof(NameRobot) << std::endl; // Inherited class should have larger size of base class 
	std::cin.get();
}