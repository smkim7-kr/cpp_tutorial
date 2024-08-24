// from computer perspective, pointers and references are the same thing
// references are not new variable unlike pointers, it needs to reference existing variable, thus not occupy memory
#include <iostream>
#define Log(x) std::cout << x << std::endl;

void Increment(int value) { // pass-by-copy, it will copy thus not affect original input variable
	value++;
}

/*
void Increment(int* value) { 
	(*value)++;
}
*/
void Increment(int& value) { // pass-by-reference, it will modify the original input variable
	value++;
}

int main() {
	int a = 10;
	int* ptr = &a; // pointer - & is operator taking memory address of variable
	int& ref = a; // reference - & is part of the type, it has different function from pointer
	// ref does not really exists, it is alias of variable a
	std::cout << ref << " will print a value 10" << std::endl;

	int b = 5;
	int c = 8;
	int& ref2 = b;
	//ref2 = c; // becomes b = 8 instead of ref2 aliasing variable c, thus switching reference is not valid

	std::cin.get();
}