// auto keyword - c++ automatically deduce the type
// use auto for long-named types or when you don't know type at all (do not use in primitive types)
#include <iostream>
#include <string>
#include <vector>
#define LOG(x) std::cout << x << std::endl

class Robot {
private:
	int m_x, m_y;
public:
	Robot()
		: m_x(0), m_y(0)
	{}

	Robot(int x, int y)
		: m_x(x), m_y(y)
	{}

	int& getX() {
		return m_x;
	}
};

std::string GetName() { // can change str::string to char* without changing code in main function
	return "Geroge";
}

int main() {
	int a = 5;
	auto b = a; // auto detects b is int
	auto c = 7.2; // auto detects c is double

	auto name = GetName(); // std::string
	int a2 = name.size(); // this will cause error when GetName() function return char*	
	// therefore, pro - can change API easily con - don't know API has been changed
	
	// Example
	std::vector<std::string> strings;
	strings.push_back("Seoul");
	strings.push_back("Tokyo");

	for (std::vector<std::string>::iterator it = strings.begin();
		it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	// using iter = std::vector<std::string>::iterator; // can define name with using keyword

	for (auto it = strings.begin(); // simplies by replacing massive type to auto
		it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	Robot r;
	const auto& r_x = r.getX(); // const and reference(&) should be called explicitly

	std::cin.get();
}