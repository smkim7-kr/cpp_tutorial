// mutable keyword - two main usage 1) with const 2) with lambda
// mutable means someting that can change
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot {
private:
	mutable int m_x = 1, m_y = 2; // mutable variable
	mutable int m_DebugCount = 0; // mutable allows the access of const methods for const instantiated objects
public:
	int GetX() const {
		m_x = 3; // member of class can be changed even though the const function is used
		m_DebugCount++; 
		return m_x;
	}

	int GetY() {
		m_y = 5;
		m_DebugCount++;
		return m_y;
	}
};

int main() {
	const Robot r1;
	r1.GetX(); // const classes can access const methods
	// r1.GetY(); // const classess cannot access non-const methods
	
	// mutable with lambdas (very rare case)
	int x = 8;
	auto f = [=]() mutable { // variable passed by value is convertable, not affecting original variable
		x++; 
		Log("Hello");
		};
	f();
	std::cin.get();
}