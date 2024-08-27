// this keyword: accessible only through member function in class
// pointer to the current class object
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot;
// Forward declarations
void PrintRobot(Robot* r);
void PrintRobotRef(const Robot& r);


class Robot {
public:
	int m_x = 0, m_y = 0;

	Robot(int x, int y)	{
		Robot* r = this; // this keyword
		// this = nullptr; // this is not allowed to reassign the address
		r->m_x = x; r->m_y = y; // or this->m_x, this->m_y alternatively

		PrintRobot(this); // passing this to function outside the class
		PrintRobotRef(*this); 

		// delete this; // avoid doing this, freeing memory from member function
	}

	/* Above method is same as
		Robot(int x, int y)
		: m_x(x), m_y(y)
	{}
	*/

	// this keyword in const methods
	int GetX() const { // const methods imply we aren't allowed to modify the class (member)
		const Robot* r = this; // therefore this must be const
		// Roobt* r2 = this; // without const will cause an error
		// r->m_x = 5; // this also causes an error
		return r->m_x;
	}
};

void PrintRobot(Robot* r) {
	std::cout << r->m_x << ", " << r->m_y << std::endl;
}

void PrintRobotRef(const Robot& r) {
	std::cout << r.m_x << ", " << r.m_y << std::endl;
}

int main() {
	// Create a Robot object
	Robot r(10, 20); // will automatically call PrintRobot and PrintRobotRef

	std::cin.get(); 
}