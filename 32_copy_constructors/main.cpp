// copying data/memory occurs a lot in c++
// avoid unnecessary copying because it takes time
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

struct Vec2 {
	int x, y;
};

class String {
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // +1 for null termination chracter
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	// Copy constructor - input of smae class const reference
	String(const String& other) // deep copy
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}
	// there are default copy constructor created by C++ 
	/*
	String(const String& other)
		:m_Buffer(other.m_Buffer), m_Size(other.m_Size)
	{}
	*/

	/* Other possible option
	String(const String& other)	{
		memcpy(this, &other, sizeof(String));
	}
	*/

	// Can disable copy constructor by
	// String(const String& other) = delete;

	~String() {
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index) {
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string); // friend keyword: can access private member of class
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_Buffer; // can access m_Buffer direcly since it is friend
	return stream;
}

void PrintString(String string) { // this will cause a lot of copying
	std::cout << string << std::endl;
}

void PrintStringRef(const String& string) { // this will prvent unnecessary copying
	// String s2 = str; // copy constructor is called here
	std::cout << string << std::endl;
}

int main() {
	// assignment opertor = is always copying except references
	int a = 2;
	int b = a; // a and b have different memory address

	Vec2 v1 = { 0, 0 };
	Vec2 v2 = v1; // struct copy, v1 and v2 have different memory address

	Vec2* pv1 = new Vec2(); // heap allocation
	Vec2* pv2 = pv1; // copying (=) the pointer, pv1 and pv2 are pointing to same memory address
	// pv2++; will not affect pv1
	// b->x = 2; will affect pv1

	// Self-defined String class
	String string = "George";
	String str2 = string; // shallow string copy: string and str2 will share the same m_Buffer memory address
	// problem - destructor will be called twice, it will cause error
	str2[2] = 'a'; // string and str2 will both change to "Gaorge"
	std::cout << string << std::endl;
	std::cout << str2 << std::endl;
	
	// solution: deep copy - string and str3 reserves their own memory, thus not affecting each other
	// deep copy is done by calling copy constructor
	String str3 = string;
	PrintString(string); // unnecessary copy
	PrintString(str3);
	PrintStringRef(string); // prevent copy
	PrintStringRef(str3);
	std::cin.get();
}