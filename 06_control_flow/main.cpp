// continue, break, return
#include <iostream>

int main() {
	// continue: only used inside loop - move to next iteration of the loop
	for (int i = 0; i < 5; ++i) {
		if (i % 2 == 0)
			continue;
		std::cout << i << std::endl;
	}
	std::cout << "only odd numbers are printed" << std::endl;

	// break: end loop
	for (int i = 0; i < 5; ++i) {
		if (i == 3)
			break;
		std::cout << i << std::endl;
	}
	std::cout << "loop exists before it prints 3" << std::endl;

	// return: end function (end program in main function)
	for (int i = 0; i < 5; ++i) {
		if (i == 3)
			return 0; // return can be used everywhere, not only in loops and functions
		std::cout << i << std::endl;
	}
	std::cout << "this line won't be printed because return will end main function immediately" << std::endl;
	std::cin.get();
}