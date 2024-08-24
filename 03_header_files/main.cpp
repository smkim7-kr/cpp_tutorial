#include <iostream> // copy iostream library directly into the main.cpp file in preprocessor step
#include "Log.h" // <> vs. "" - <> search files in include directory, "" is local thus using relative path e.g. "../../Log.h"
///NOTE: c header files has .h extensions e.g. #include <stdio.h>

int main() {
	InitLog();
	Log("Hello world!");
	std::cin.get();
}