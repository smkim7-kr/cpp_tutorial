#pragma once // header file that only include once in single translation unit/cpp file

// any other files that uses declared function in header file can add '#include "Log.h"'
void Log(const char* message); // header files have declaration of functions

void InitLog();