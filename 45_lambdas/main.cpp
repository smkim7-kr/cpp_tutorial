// lambda function - annonymous function (something like quick disposable function)
// whenever there is function pointer, can use lambda function
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::find_if
#define LOG(x) std::cout << x << std::endl

void ForEach(const std::vector<int>& values, void(*func)(int)) { // function pointer func with input int and output void 
	for (int v : values)
		func(v); // func is lambda function defined in main function
}

// NOTE: cppreference.com is great page to reference anything of C++
int main() {
	std::vector<int> values = { 1, 2, 4, 5 };
	auto lambda = [](int v) {std::cout << "Value: " << v << std::endl; }; // [ captures ](intpt) { function definition } 
	ForEach(values, lambda); 

	// captures - to put outside variables into lambda function
	int a = 5; // how can I use a into a lambda function?
	auto lambdaval = [=](int v) {std::cout << "Value: " << a << std::endl; }; // 1) pass everything byvalue 
	auto lambdaref = [&](int v) {std::cout << "Value: " << a << std::endl; }; // 2) pass everything by reference
	auto lambdavala = [a](int v) {std::cout << "Value: " << a << std::endl; }; // pass a by value
	auto lambdarefa = [&a](int v) {std::cout << "Value: " << a << std::endl; }; // pass a by reference

	ForEach(values, lambda); // cause error

	// Use example
	std::vector<int> values2 = { 1, 2, 4, 5 };
	auto it = std::find_if(values2.begin(), values2.end(), [](int v) { return v > 3; }); // first number greater than 3
	std::cout << *it << std::endl; // 4

	std::cin.get();
}