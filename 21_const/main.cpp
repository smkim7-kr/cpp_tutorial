// const keyword - promise that something will not change 
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot {
private:
	int m_x, m_y;
	const int* const pm_x;
	// NOTE: int* m_x, *m_y => m_y without * will make integer variable
public:
	// Constructor to initialize members
	Robot(int x, int y, const int* ptr)
		: m_x(x), m_y(y), pm_x(ptr) {
	}

	int GetX() const { // const after method name - cannot change member variables (only works in class)
		// m_x = 3; // cannot modify!
		return m_x;
	}

	int GetX() { // function overloading: one with const, one w/o const
		return m_x;
	}

	const int* const GetPointerX() const { // return pointer that cannot modify content/address and class Robot member variable
		return pm_x;
	}
	void SetX(int x) {
		m_x = x;
	}
};

void PrintRobot(const Robot& robot) {
	// if GetX() isn't a const function this will cause error
	std::cout << robot.GetX() << std::endl;
}

int main() {
	int a = 5;
	a = 2;

	// const variable
	const int b = 5;
	//b = 5; // this will cause eerror

	const int MAX_CAPACITY = 200; // use const in variable that doesn't wants to be "varaible"
	
	// const of pointer
	int* c = new int; // pointer w/o const
	*c = 2; // 1) can change the content of c
	c = &a;  // 2) can change the address of c

	const int* c2 = new int; // cannot change the content
	int const* c3 = new int; // cannot change the content
	// *c2 = 3; *c3 = 3; // this gives an error

	int* const c4 = new int; // cannot change the address - const after *
	// c4 = nullptr; // this gives an error

	const int* const c5 = new int; // cannot change both content and address

	// const in class
	int initial_value = 10;
	Robot* r = new Robot(5, 10, &initial_value); 
	r->SetX(10);
	PrintRobot(*r);


	std::cin.get();
}