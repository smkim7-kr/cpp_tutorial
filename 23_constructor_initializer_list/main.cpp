// initialize member variables in constructor - must use constructor initialize list! (better performance)
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot {
private:
	int m_x, m_y;
public:
	Robot()
		: m_x(0), m_y(0) 
	{}

	// Same as Robot(int x, int y) { m_x = x; m_y = y; }
	Robot(int x, int y)
		: m_x(x), m_y(y) // some compiler will show error when intialized in different order from member initalized order of the class
	{}
};

int main() {
	// if constructor initialize member inside the function, they are called twice (first in default constructor, second in the defined constructor function)
	// if constructor initializer list is used, members will be only called once
	Robot r; // same as Robot r()
	std::cin.get();
}