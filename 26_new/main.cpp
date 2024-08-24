// new keyword - computer should find continuous free memory of object size in the heap
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

	Robot(int x, int y)
		: m_x(x), m_y(y)
	{}
};

int main() {
	// new is just operator - we can overload new operator
	int a = 2;
	int* b = new int; // 4 bytes allocation to heap
	int* c = new int[50]; // 200 bytes allocation to heap

	delete b; delete[] c; // delete is also an operator + calls destructor

	Robot* r = new Robot(); // allocate memory + calls default constructor
	// Robot* r = (Robot*)malloc(sizeof(Robot)); // C-style : purely allocate memory w/o calling default constructor *NEVER USE THIS IN C++*
	Robot* r2 = new Robot[30]; // 30 Robot objects continguous size allocation to heap
	

	Robot* r3 = new(r2) Robot(); // placement new to optimize code

	delete r; 
	delete[] r2;

	std::cin.get();
}