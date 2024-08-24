// interfaces: special types of virtual functions - "pure virtual functions'
// guarantee classes to have certain function (interface of parent class) to instantiate
// force subclass to implement a function by not implementing anything on base class
#include <iostream>
#define Log(x) std::cout << x << std::endl;

class Printable {
public:
	virtual std::string GetClassName() = 0; // interface
};

// Inherit Printable
class Robot : public Printable { // class with intefaces cannot be instantiated
public:
	virtual std::string GetName() = 0; // interface
	std::string GetClassName() override { return "Robot"; } // override keyword is option, but try to use it for clarity!
};

class NameRobot : public Robot {
private:
	std::string m_Name;
public:
	NameRobot(const std::string& name) {
		m_Name = name;
	}

	std::string GetName() override { return m_Name; } // must define overrided function that is interface in base class Robot
	std::string GetClassName() override { return "NameRobot"; } // if this is not defined, NameRobot class will also use GetClassName() methods from Robot class
};

void PrintClass(Printable* obj) {
	std::cout << obj->GetClassName() << std::endl; // obj supports polymorphism, Robot/NameRobot can all use this function
	
}

int main() {
	// Robot* r = new Robot(); // cannot instantiate Robot class because it has interface
	Robot* r = new NameRobot("AlphaGo");
	NameRobot* nr = new NameRobot("Nuro");

	PrintClass(r);
	PrintClass(nr);
	// PrintClass(new Printable()) // Printable class only has GetClassName() interface, thus cannot use that class
	std::cin.get();
}