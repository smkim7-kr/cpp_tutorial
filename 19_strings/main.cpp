// strong - group of characters
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

void Print(const std::string& string) { // copy string by const reference! // (std::string string) cannot modify string and copying is slow
	Log(string)
}

int main() {
	// char - 8 bits
	// cannot fit all languages with 2^8 combintations! utf-16 etc. variants exists
	// "nomral" char - 1 byte = 8 bits
	// string is array of chars(characters)
	const char* name = "George"; // C-style way, we don't need to delete just because it is pointers!
	strlen(name);
	// name[1] = 'a'; // cannot change since the variable is const
	// memory saves ascii value of characters contiguously
	// null termination character - 00, computer knows this signifies the end of the string/array
	// therefore although name is a pointer, computer can realize when it ends
	char name2[6] = { 'G', 'e', 'o', 'r', 'g', 'e' }; // NOTE: character use single quote '', sting use double quote ""
	// computer doesn't know when name2 character array ends
	char rightname2[7] = { 'G', 'e', 'o', 'r', 'g', 'e', '\0'}; // \0 is null termination character (or numeric value 0)
	// computer now knows when rightname2 character array ends

	// templated version of string - std::string
	// use std::string to stengten the code - underlying data structure is just array of chars
	// use #incldue <string> header file - overload of operator like << defined
	std::string name3 = "Geroge"; // by default this makes const char array, thus cannot change this variable
	Log(name3);
	name3.size();

	// appending strings
	// std::string wrong =  "Hello" + "World!" // gives an error
	std::string right1 = "Hello";
	right1 += "World!"; // += operator is overloaded, so const constraint doesn't apply here
	std::string right2 = std::string("Hello") + "World!";

	bool contains = right2.find("lo") != std::string::npos;
	std::cin.get();
}