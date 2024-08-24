// operator e.g. new, &, *, +, != ,(comma) and others
// overloading: redefine/change behavior of operator
// use overloading only if makes sense - use it minimally!
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

struct Vec3 {
	float x, y, z;

	Vec3(float x, float y, float z)
		: x(x), y(y), z(z) {}

	Vec3 Add(const Vec3& other) const {
		// return operator+(other); or *this + other; // alternative
		return Vec3(x + other.x, y + other.y, z + other.z);
	}

	Vec3 operator+(const Vec3& other) const {
		// return Vec3(x + other.x, y + other.y, z + other.z); // alternative
		return Add(other);
	}
};

std::ostream& operator<<(std::ostream& stream, const Vec3& pos) {
	stream << pos.x << ', ' << pos.y << ', ' << pos.z; // stream has defined << operator on floats
	return stream;
}

int main() {
	Vec3 position(3.0f, 1.5f, 0.1f);
	Vec3 speed(0.4f, 0.5f, 0.3f);
	
	Vec3 newpos = position.Add(speed); 
	Vec3 dirtypos = position.Add(newpos.Add(speed)); // get dirty when these functions are called multiple times

	// operator + overloading
	Vec3 goodpos = position + speed; // much cleaner code!

	// operator << overloading
	std::cout << goodpos << std::endl;
	std::cin.get();
}