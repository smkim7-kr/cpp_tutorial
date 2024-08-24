// stack memory 
// heap memory - can change memeory size
// both stack and heap are inside RAM
// why memory? stroe data, instruction, program etc.
#include <iostream>
#include <string>
#define Log(x) std::cout << x << std::endl;

class Robot {
private:
	int m_x, m_y;
public:
	Robot()
		: m_x(0), m_y(0)
	{}

	Robot(int x, int y)
		: m_x(x), m_y(y)
	{}
};

int main() {
	// stack allocation
	int sval = 5;
	int sarr[5];
	Robot sr;
	// sval, sarr, sr are closely togehter in memory 
	// stack pointers are incremented - thus stack allocation (only 1 cpu instruciton) is much faster than heap 
	
	// heap allocation
	// when new is called, underlying malloc function is called, which is very complex
	// go through free list, ask for memory, book keep
	int* hval = new int; *hval = 5; // smart pointer do same thing
	int* harr = new int[5];
	Robot* hr = new Robot();
	// hval, harr, hr memory address are not close

	delete hval; delete[] harr; delete hr; // must call delete when new heap-allocated memory is instantiated


	// allocation >> access/cache miss - allocation is main cause for the time difference between stack and heap
	std::cin.get();
} // stack-allocated objects freed automatically when scope ends