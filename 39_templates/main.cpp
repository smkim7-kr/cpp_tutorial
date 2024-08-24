// templates - something like macro
// compiiler writing code for you with some rules defined by you (like blueprint)
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

// template does not exist until we call it
// template<class HAHA> // Can use class instead of typename, and anything instead of T
template <typename T> // template - evaluated at compile time
void Print(T val) { // avoid code duplication of type-based overloading function
	std::cout << val << std::endl;
}

template <typename T, int N> 
class Array {
private:
	T m_Array[N]; // size and array type determined at compile time
public:
	int GetSize() const { return N; }
};

int main() {
	// e.g. function that does something, but different input types
	Print(5); // T is int
	Print("Hello"); // T is const char[]
	Print(2.5); // T is double
	Print<int>(5); // can pre-define T

	// e.g. template that determines array size at compile time
	Array<int, 10> arr;
	std::cout << arr.GetSize() << std::endl; // 10

	// When template gives an error, it is difficult to debug (we don't know what code is compiled)
	// template is fragile and very difficult to understand
	// in this case, just use overloading
	std::cin.get();
}