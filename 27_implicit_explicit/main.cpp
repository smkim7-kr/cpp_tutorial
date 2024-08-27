// implicit - automatic conversion e.g data conversion
// explcit - bans implicit conversions
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot {
private:
	int m_x, m_y;
	std::string name;
public:
	Robot()
		: m_x(0), m_y(0), name("None")
	{}

	Robot(int x, int y)
		: m_x(x), m_y(y), name("None")
	{}

	Robot(std::string name)
		: m_x(-1), m_y(-1), name(name)
	{}

	explicit Robot(int x, int y, std::string name) // explicit constructor
		: m_x(x), m_y(y), name(name)
	{}

	void Print() const
	{
		std::cout << m_x << ", " << m_y << ", " << name << std::endl;
	}
};

void PrintRobot(const Robot& robot) {
	robot.Print();
}

int main() {
	Robot r(3, 4); 
	Robot r2 = { 3, 4 }; // implicit conversion
	Robot r3 = std::string("George");
	PrintRobot({ 2, 4 }); // can pass {2,4} by reference
	const std::string str = "George";
	PrintRobot(str); // cannot pass const char, but strong is possible
	PrintRobot(Robot("Georgie"));

	// Robot r4 = {4, 5, "George"} // error due to explicit constructor
	Robot r4(4, 5, "George");
	Robot r5 = Robot(4, 5, "George");
	std::cin.get();
}