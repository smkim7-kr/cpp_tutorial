// stack vs. heap
// stack-based variable is destroyed when scope (function, if statement, loop , empty scope {}) ends
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot {
private:
	int m_x, m_y; // m_x, m_y is in class scope
public:
	Robot()
		: m_x(0), m_y(0)
	{
		std::cout << "Created Entity" << std::endl;
	}

	~Robot() {
		std::cout << "Destroyed Entity" << std::endl;
	}

};

// This function is wrong
int* CreateArray() {
	int array[50]; // allocate on stack
	return array; // return pointer to stack memory
} // that stack memory is freed after function ends!

int* CreateArraySol() {
	int* array = new int[50]; // Solution 1: allocate array to heap
	return array; 
} 

void CreateArraySol2(int* array) {
	// Solution 2: use array as input
}

class ScopedPtr { // this is what smart pointers do: automatic delete
private:
	Robot* m_r;
public:
	ScopedPtr(Robot* r)
		:m_r(r) {}

	~ScopedPtr() {
		delete m_r;
	}
};

int main() {
	{
		Robot r; // created on stack
	} // Robor r "Destroyed Entity" called here

	{
		Robot* r = new Robot(); // created on heap
	} // not destroyed here 
	
	int* a = CreateArray(); // pointer a points to already freed memory!
	int* b = CreateArraySol(); // pointer b points to first element addreess
	int* arr = new int[50];
	CreateArraySol2(arr);

	// Better solution: used scoped pointer (automate new and delete step) - unique pointer
	{
		ScopedPtr sptr = new Robot();
	} // sptr is destroyed here
	std::cin.get();
}