#include <iostream>
#include <string>
#include <stdlib.h>
#define Log(x) std::cout << x << std::endl;

int main() {
	"George"; // string literals - by default const char[7] (extra character is null termination character '\0' or 0)
	const char name[9] = "Ger\0rge"; 
	Log(name); // only prints Ger
	strlen(name); // 3

	// char* name2 = "Geroge"; // this will generate an error because w/o const
	// this is because string literals are stored under READ-ONLY memory
	// if to avoid const constraint, use char array rather than char pointer
	char* gname = (char*)"George"; // or cast it into char* manually

	// Different char types
	const wchar_t* name2 = L"George"; // wide character (2/4 byte depending to compiler)
	const char16_t* name3 = u"Geroge"; // 2 byte (utf-16)
	const char32_t* name4 = U"George"; // 4 byte (utf-32)
	
	// C++14
	using namespace std::string_literals;
	// std::string wrong = "Hello" + "World!"
	std::string newoption = "Hello"s + "World!"; // add s at the end of string to append directly
	std::wstring ws = L"Hello"s + L"World!";
	const char* example = R"(L1
		L2
		L3
		L4)"; // R ignores escape character

	// string literals are always stored in read-only memory
	char ex[] = "What"; // not necessary to use const for char ARRAYS (NOT POINTERS)
	ex[2] = 'a'; // how to edit? they are copied data to modifiable area
	std::cin.get();
}