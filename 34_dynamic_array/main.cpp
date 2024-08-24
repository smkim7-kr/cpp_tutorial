// Standard Template Library (STL) - only users decide the data type, others are made by template
// std::vector - dynamic array data structure (can change the size) 
// not very fast DS - when size excees buffer, it finds new memory storage and copy everything to new space (overhead exists here)
#include <iostream>
#include <string>
#include <vector>
#define Log(x) std::cout << x << std::endl;

struct Vec3 {
	int x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vec3& vec3) {
	stream << vec3.x << ", " << vec3.y << ", " << vec3.z;
	return stream;
}

void foo(const std::vector<Vec3>& v) {} // pass by reference!

int main() {
	// raw array - size cannot be changed
	Vec3 v[5];
	Vec3* vptr = new Vec3[5]; 

	// vector
	std::vector<int> arr;
	std::vector<Vec3> vectors; // stack-cllocated : technically more optimal because stored data memory is contiguous
	// problem - resizing vecotr can be very slow, especially when the size is large
	std::vector<Vec3*> vectorptrs; // heap-allocated : resizing vector is faster than stack-allocated approach

	vectors.push_back({ 2, 3, 4 });
	vectors.push_back({ 5, 7, -1 });
	for (int i = 0; i < vectors.size(); i++)
		std::cout << vectors[i] << std::endl; 
	for (const Vec3& v : vectors) // another possible approach - & to prevent copying
		std::cout << v << std::endl;
	vectors.erase(vectors.begin() + 1); // (iterators) : erase second element
	vectors.clear();

	std::cin.get();
}