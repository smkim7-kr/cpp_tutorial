#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

int main() {
	int a = 8;
	int b = a > 5 ? 10 : 5; // if (a>5), b=10, else b=5
	int c = b > 5 ? b > 10 ? 15 : 10 : 5; // if b>5 (if b>10, c=15, else c=10) else c=5
	std::cin.get();
}