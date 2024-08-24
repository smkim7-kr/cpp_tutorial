// static: 1) outside of class/struct 2) insider class/struct
// 1) outside - declared symbol/variable will be visible only to the translation unit
// 2) inside - all instances share the static variable/method
#include <iostream>
#define Log(x) std::cout << x << std::endl;

int s_var = 10; // linking with no problem since s_var defined at static.cpp file is internal to that file, main.cpp does not detect the variable!
//extern int s_var; // external linkage to NON-STATIC s_var in other file
//int func() {}; 

// why static?
// to prevent global variable names' duplications
// make it static unless it needs to link to other translation units

struct Robot {
	int x, y;
	void Print() {
		std::cout << x << ", " << y << std::endl;
	}
};

struct s_Robot {
	static int x, y;
	void Print() {
		std::cout << x << ", " << y << std::endl;
	}

	/*
	static void Print() {
		std::cout << x << ", " << y << std::endl;
	}
	*/
};
int s_Robot::x, s_Robot::y; // static variables need to be initialized out of the struct/class first

int main() {
	Log(s_var);
	
	Robot r1 = { 0, 7 };
	r1.Print();

	Robot r2 = { -1, 3 };
	r2.Print();

	s_Robot sr1;
	sr1.x = 0; sr1.y = 7;
	s_Robot sr2;
	sr2.x = -1; sr2.y = 3;
	sr1.Print(); // -1, 3 because static variables are shared for all struct instances
	sr2.Print(); // -1, 3
	std::cout << s_Robot::x << ", " << s_Robot::y << std::endl; // can also use <struct/class name>::

	// static methods cannot access non-static variables
	std::cin.get();
}