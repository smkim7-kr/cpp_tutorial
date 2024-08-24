// static arrays
// arrays with constant size after initialized
#include <iostream>
#include <string>
#include <array>
#define LOG(x) std::cout << x << std::endl

void PrintArray(int* array, unsigned int size) { // old style problem - we should track the size of the array explicitly
	for (int i = 0; i < size; i++) 
		std::cout << array[i] << std::endl;
}

// void PrintNewArray(const dtd::array<int, ?>& data) {} // how to pass new-style parameter as function input?
/* Solution - use templates
template <int size>
void PrintNewArray(const dtd::array<int, size>& data) {}
*/

int main() {
	// both style are stored in stack
	std::array<int, 5> arr; // new style
	int oldarr[5]; // old style - doesn't mean new style is better

	// which style should we use? new-style is preferred to old-style (because new-style's perfomance cost is minimal & keep track of array size)
	arr.size(); // new style has own method to call size, old style should keep it size expicitly
	arr.begin(); arr.end(); // new style supports iterators

	// arr[5] = 10; // this violates bound, with enough debuge level, alerts error (pro: bound checking, con: checking takes overhead)
	// oldarr[5] = 10; // old orray does not finds for bound error 

	std::cin.get();
}