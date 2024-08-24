// enumerators(enums): grouping variables with logical sense
#include <iostream>
#define Log(x) std::cout << x << std::endl;

// Ungrouped variables
int a = 0;
int b = 1;
int c = 2; 

// Logically grouped
enum Choice { // enum in default use 32-bit integer
	A, B, C
};

enum Choice2 { // be careful for conflicing names - cannot use A, B, C here
	A2=-1, B2=4, C2=9
};

enum Choice3 : unsigned char {
	A3=5, B3, C3
};

enum Choice4 {
	A4=7, B4, C4  // 7, 8, 9
};

int main() {
	Choice choice = B;
	if (choice == 1)
		Log("This will be printed");

	Log(Choice4::C4); // 9

	std::cin.get();
}