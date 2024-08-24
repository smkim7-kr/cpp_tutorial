// function pointers: to assign a function into a variable
// normal usage - to "call" a function with input and output
// by assigning into variables - can pass functions into other functions etc.
// they are used in old C-style codes, not used in recent days
#include <iostream>
#include <string>
#include <vector>
#define LOG(x) std::cout << x << std::endl

void Print() {
	std::cout << "Hello World!" << std::endl;
}

void PrintWInput(int a) {
	std::cout << "Hello World! " << a << std::endl;
}

void PrintValue(int v) {
	std::cout << "Value: " << v << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int)) { // function pointer func with input int and output void - use PrintValue funciton here
	for (int v : values)
		func(v); // execute PrintValue function
}

int main() {
	Print(); // normal usage

	// auto is useful for function pointers
	// auto function = Print(); // this causes an error because Print function returns void tyoe
	auto function = Print; // without (), it is retrieving memory address of function Print (cpu instructions)
	// auto function = &Print // same as above, we don't need & due to implicit conversion
	function();
	function(); // can call function twice

	// void(*function)(); // actual type of function pointer
	// confusing!! - create alias using typedef
	typedef void(*func)(); // same as typedef void(*function)() func;
	func ffunction = Print;
	ffunction();
	
	// with input
	typedef void(*funcwint)(int);
	funcwint function2 = PrintWInput;
	function2(5);
	function2(10);

	std::vector<int> values = { 1, 2, 4, 5 };
	// how to iterate using functions?
	ForEach(values, PrintValue); // Not PrintValue()

	// Problem: we need to expicitly define PrintValue function in the code with multiple lines 
	// Solution: lambda function
	ForEach(values, [](int v) {std::cout << "Value: " << v << std::endl; }); // [](intpt) { function definition } 
	std::cin.get();
}