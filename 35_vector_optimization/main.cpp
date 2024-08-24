// Optimizing vector
// avoid copying vector, expanding vector size
#include <iostream>
#include <string>
#include <vector>
#define Log(x) std::cout << x << std::endl;

struct Vec3 {
	int x, y, z;

	// Constructor
	Vec3(int x, int y, int z)
		:x(x), y(y), z(z)
	{}

	// Copy constructor
	Vec3(const Vec3& other)
		: x(other.x), y(other.y), z(other.z)
	{}
};

int main() {
	std::vector<Vec3> vectors;
	vectors.push_back({ 2, 3, 4 });
	vectors.push_back({ 5, 7, -1 });
	vectors.push_back({ 2, 0, 9 });
	// this creates 6 copies!
	// because constructing Vec3 is on main function stack, so need to put it to vec3's allocated address
	// Optimization 1) directly construct on class object's memory
	// because vector needs to resize the memory when capacity is reached
	// Optimization 2) if we know the size, pre-define the capacity of the vector
	std::vector<Vec3> vectors2;
	vectors2.reserve(3); // reserve 3 Vec3 objects can put into vectors
	vectors2.emplace_back(Vec3(2, 3, 4 )); // use emplace_back, thus obejcts are constructed directly to its memory (rather than main function stack)
	vectors2.emplace_back(Vec3(5, 7, -1));
	vectors2.emplace_back(Vec3(2, 0, 9));
	std::cin.get();
}