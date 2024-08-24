// two considerations when declaring variable
// 1) lifetime: how long it will remain in memory
// 2) scope: where can be access the variable
// static local: lifetime reserves until the end of the program, scope is limited
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

// int i = 0  in global scope (can access i outside function foo())
void foo() {
	static int i = 0; // static variable i will be initialized only at first call of the function
	i++;
	Log(i);
}
class Singleton { // only one instance for the class
private:
	static Singleton* s_instance;
public:
	static Singleton& Get() { return *s_instance; }
	void foo() {}
};

Singleton* Singleton::s_instance = nullptr; // extenral definition

class StaticSingleton {
public:
	static StaticSingleton& Get() {
		static StaticSingleton instance; // static - extending lifetime until to end of program
		return instance;
	}
};

int main() {
	foo(); // i=1
	foo(); // i=2
	foo(); // i=3

	Singleton::Get().foo(); // this is quite dirty
	StaticSingleton::Get(); // much better approach - static get methods
	std::cin.get();
}