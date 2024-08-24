// while and for - when codes need to be runned multiple times
#include <iostream>

int main() {
	std::cout << "ahh this is inefficient!" << std::endl;
	std::cout << "ahh this is inefficient!" << std::endl;
	std::cout << "ahh this is inefficient!" << std::endl;
	std::cout << "ahh this is inefficient!" << std::endl;
	std::cout << "ahh this is inefficient!" << std::endl;

	for (int i = 0; i < 5; ++i) { // (initiatization ; condition ; update)
		std::cout << "using for loop is more efficient" << std::endl;
	}

	int j = 0;
	for (; j < 5; ) { // you can leave it blank
		std::cout << "it is valid to blank for loop" << std::endl;
		j++;
	}

	int i = 0;
	while (i < 5) {
		std::cout << "you can use while loop instead of for loop" << std::endl;
		i++;
	}

	int k = 0;
	do {
		std::cout << "do-while loop will execute at least one" << std::endl;
		k++;
	} while (k < 5);

	std::cin.get();
}