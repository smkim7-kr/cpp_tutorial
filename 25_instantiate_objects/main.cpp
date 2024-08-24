// Two choices (respect to memory) - stack, heap
// stack objects: automatic lifespan (live in the scope)
// heap objects: lifespan defined by programmer
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot{
private:
	int m_x, m_y;
public:
	Robot()
		: m_x(0), m_y(0)
	{}

	Robot(int x, int y)
		: m_x(x), m_y(y) 
	{}

	const int GetPositionX() const { return m_x; }
};

void newScope() {
	Robot localr = Robot(4, 5);
} // Robot localr is destroyed after this function scopr

int main() {
	// Instantiating objects on stack - use this option whenever it's possible
	// because fastest way to insantiate objext
	Robot r; // calling Robot() default constructor
	int x = r.GetPositionX(); // x = 0

	Robot r2(3, 4); // Robot r2 = Robot(3, 4)
	int x2 = r2.GetPositionX(); // x2 = 3

	// If want objects to live outside the scope
	// or if wants to store large size object (since stack is small area) 
	Robot* robotptr;
	{	
		Robot pr(7, 8);
		Robot* pr2 = new Robot(3, 4); // heap-allocated Robot object
		robotptr = pr2;
		Log(pr2->GetPositionX());
		delete pr2;
	} // pr destroys here

	delete robotptr; // robotptr destroys here

	std::cin.get();
}