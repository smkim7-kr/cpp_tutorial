// constructor - special type of function that is called when instantiating the object
// destructor - special type of function that is called when destorying the object
#include <iostream>
#define Log(x) std::cout << x << std::endl;

class Robot {
public:
	int m_x, m_y;

	// Robot() {} // Default constructor: this is called when no constructor is defined explicitly
	Robot() { // Constructor: x and y is set to 0 when Robot class is instantiated, <class/struct name>(), no return type
		m_x = 0; 
		m_y = 0;
	}

	Robot(int x, int y) { // Constructor overloading
		m_x = x;
		m_y = y;
	}

	~Robot() { // destructor - useful when freeing heap-allocated memory
		std::cout << "Bye bye robot!" << std::endl;
	}

};

// preventing users to instantiate class
class noInstantiate {
private:
	noInstantiate(); // Method 1: Make constructor private
public:
	// noInstantiate() = delete; // Method 2: delete constructor
};

int main() {
	Robot r1;
	std::cout << r1.m_x << ", " << r1.m_y << std::endl; // 0, 0
	Robot r2(10, 9);
	std::cout << r2.m_x << ", " << r2.m_y << std::endl; // 10, 9

	{
		Robot r3(10, 10);
	} // r3's destructor is called here - when to scope ends

	// noInstantiate() // this arises error since constructor is deleted
	std::cin.get();
}