// visibility - no affect to how program runs/performance, help for better code
// 3 types - private, protected, public
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

struct sRobot { // struct: default visibility is public
	int x, y;
};

class Robot { // class: default visibility is private
private: // only this class can access (read, write) / exception - 'friend' can access private members/methods
	int X, Y;
	void Print() {};
protected: // class and all subclasses can access
	int pX, pY;
public:
	Robot() { X = 2; Y = 1; Print(); } // Print() private method can be access inside the class
};

class NameRobot : public Robot {
public:
	NameRobot() { pX = 10; pY = 20; } // can access pX, pY from Robot class since they have protected visibility
	void PrintName() { Log("Name"); }
};
int main() {
	Robot* r = new Robot();
	// r.X = 2; // this is not allowed since X is private member
	// r.Print() // this is also not allowed

	NameRobot* nr = new NameRobot();
	// nr.pX = 10; // this is not allowed
	nr->PrintName(); // this is allowed since PrintName() is public method

	// therefore, visibility is for the people who read/fix the code 
	// visibility is not understood by cpus, computers etc.
	// e.g. private - it signals you should not access this outside the class
	std::cin.get();
}