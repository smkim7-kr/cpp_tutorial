// Log.cpp file has definition of declared function from Log.h file
#include <iostream>
#include "Log.h"

// void Log(const char* message); // function declaration, it finds the function from main.cpp file -> moves into header file

void InitLog() {
	Log("Initialize log");
}

void Log(const char* message) {
	std::cout << message << std::endl;
}