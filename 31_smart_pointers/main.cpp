// smart pointers - automatic new/delete process (unique pointer, shared pointer, weak pointer)
// avoid new/delete if possible, use smart pointers
// use unique pointer first, only used shared pointer when copying is necessary
#include <iostream>
#include <string>
#include <memory> // required header to use smart pointers
#define Log(x) std::cout << x << std::endl;

class Robot {
private:
	int m_x, m_y;
public:
	Robot()
		: m_x(0), m_y(0)
	{}

	Robot(int x, int y)
		: m_x(x), m_y(y)
	{}

	int GetX() const {
		return this->m_x;
	}
};

int main() {
	// unique pointer: pointer destroyed when out of scope, cannot copy unique pointer to prevent copied pointer pointing to freed memory
	// stacked allocated object, low overhead
	{ // empty scope
		std::unique_ptr<Robot> robot(new Robot());
		// std::unique_ptr<Robot> robot = new Robot(); // not allowed implicit way
		robot->GetX();

		std::unique_ptr<Robot> robot2 = std::make_unique<Robot>(); // preferred way to instantiate unique pointer, safer
		robot2->GetX();

		// std::unique_ptr<Robot> r2 = robot; // this is not allowed! copying is disallowed
	} // unique pointer destroys here


	// shared pointer: copying allowed (reference counting used - track how many references)
	// deleted when reference count = 0, higher overhead than unique pointer due to reference count
	std::shared_ptr<Robot> sharedRobot2;
	{
		std::shared_ptr<Robot> sharedRobot = std::make_shared<Robot>(); // instatinating with new will cause error - create two reference counting block
		sharedRobot2 = sharedRobot; // copying is allowed
	} // reference count = 1 (pointed by sharedRobot2), thus not destroyed here 

	// weak pointer: no reference count increase
	// used to copty shared pointer, but not want to take ownership of entity
	std::weak_ptr<Robot> weakRobot;
	{
		std::shared_ptr<Robot> sharedRobot = std::make_shared<Robot>(); // reference count = 1
		weakRobot = sharedRobot; // reference count = 1
	} // reference count = 0, thus destryoed here



	std::cin.get();
}