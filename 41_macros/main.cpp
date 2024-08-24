// macro: use preprocessor to automate a process (replace argument to process)
// vs. templates: templates are evaluated at compile time, macro is pure text
// do not overuse them!
#include <iostream>
#include <string>
#define WAIT std::cin.get() // whenever accounting WAIT, replace to std::cin::get()
#define LOG(x) std::cout << x << std::endl 

// change macro properties in debug and release mode
// Add PR_DEBUG (user-defined macro) in Debug mode, and PR_RELEASE in Relase mode in Project >> Properties >> C/C++ >> Preprocessor >> Preprocessor Definitions
#ifdef PR_DEBUG // #define PR_DEBUG 1 #ifdef PR_DEBUG == 1 (PR_DEBUG=1 instead of PR_DEBUG in properties)
#define LOG(x) std::cout << x << std::endl // log in debug mode 
#else //elif defined(PR_RELEASE)
#define LOG(x) // log nothing in release mode
#endif

#if 0 
// can deactivate certain code using if-endif preprocessors
#endif

// Multi-line example using backslash
// Do not put a space before or after the backslash
#define MAIN int main()\
{\
	std::cin.get();\
}

int main() {
	WAIT; // never use such macro - this is stupid code because it confuse other users & other files
	LOG("George"); // better usage - can simply the process
}