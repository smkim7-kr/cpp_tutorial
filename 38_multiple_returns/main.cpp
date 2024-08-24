// best way - return using struct
#include <iostream>
#include <string>
#include <array>
#include <tuple> // to use tuple
#define Log(x) std::cout << x << std::endl;

void multipleReturns(int& a, std::string & str) {
	a = 2;
	str = "Bad";
}

void multipleReturnspPtr(int* aout, std::string* strout) {
	if (aout)
		*aout = 10;
	if (strout)
		*strout = "Not good yet";
}

static std::array<std::string, 2> multipleReturnspArray() {
	std::string str1 = "Hello";
	std::string str2 = "World!";
	std::array<std::string, 2> outputs;
	outputs[0] = str1;
	outputs[1] = str2;
	return outputs;
}

static std::tuple<std::string, std::string> multipleReturnspTuple() {
	std::string str1 = "Hello";
	std::string str2 = "World!";
	return std::make_pair(str1, str2);
}

static std::pair<std::string, std::string> multipleReturnspPair() {
	std::string str1 = "Hello";
	std::string str2 = "World!";
	return std::make_pair(str1, str2);
}

struct StrInt { // multiple data that 1) created on stack 2) Use heteregenous types 3) access through names, not index
	std::string name;
	int size;
};

static StrInt multipleReturnsStruct() {
	std::string str1 = "Hello";
	int size = 6;
	return { str1, size };
}

int main() {
	// Method 1: pass multiple inputs by reference, make function void
	int a1 = 3;
	std::string str1 = "Method1";
	multipleReturns(a1, str1); // Good: prevent unnecessary copying
	Log(a1); Log(str1); // 2, "Bad"

	// Method 1' - small improvment by adding options of None (nullptr) and update only if ptr reserves some memory
	multipleReturnspPtr(&a1, &str1);

	// Method 2 - return array
	auto arr = multipleReturnspArray();

	// Method 3  - tuple/pair 
	// can handle return type that may not match
	std::tuple<std::string, std::string> t = multipleReturnspTuple(); // tuple
	std::cout << std::get<0>(t) << ", " << std::get<1>(t) << std::endl; // Problem: getting data is not clear (getting index instead of name) and bad code style

	auto p = multipleReturnspPair(); // pair
	std::cout << p.first << ", " << p.second << std::endl; // still not clear what is first and second

	// Method 4 (best way) - struct
	StrInt si = multipleReturnsStruct();
	std::cout << si.size << ": " << si.name << std::endl; // access through names reather than index
	std::cin.get();
}