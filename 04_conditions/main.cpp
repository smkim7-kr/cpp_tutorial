// conditions and branching jumps different areas of memory, thus there are overheads
#include <iostream>

int main() {
	int x = 5;
	bool comparison = x == 5; // == operator are implemented for comparing two imtegers
	if (comparison) // comparsion - true/false?
	{
		std::cout << "x is 5!" << std::endl;
	}

	if (0)
	{
		std::cout << "0 is false, so this will not be printed" << std::endl;
	}

	const char* ptr = "haha";
	if (ptr)
		std::cout << "anything that is not null and 0 is true" << std::endl;

	const char* ptr2 = nullptr;
	if (ptr2)
		std::cout << "nullptr is false" << std::endl;
	else if (ptr2 == "hee")
		std::cout << "this is not also true" << std::endl;
	else
		std::cout << "this will be printed because if condition has false statement" << std::endl;
	std::cin.get();
}