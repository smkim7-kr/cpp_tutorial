//arrays - collection of variables (usually in same type)
#include <iostream>
#include <string>
#include <array>
#define Log(x) std::cout << x << std::endl;

int main() {
	int example[5]; // array of 5 integers
	example[2] = 10; // third element to 10
	//example[5] // this is accessing memory out of bound. WARNING! this will not show error in Release mode, so be careful

	// array stores data continguously
	for (int i = 0; i < 5; ++i)
		example[i] = 10; // take offset of memory from the beginning (i*sizeof(int))
	
	// array is a pointer
	int* ptr = example; // points to first element address memory
	*(ptr + 2) = 6; // this is same as example[2] = 6;
	*(int*)((char*)ptr + 8) = 6; // same as above code

	// array in heap 
	int* heaparray = new int[5]; // function returning new array - need to use heap initialized array
	for (int i = 0; i < 5; ++i)
		heaparray[i] = 10;
	delete[] heaparray; // need to free memory using delete
	// if possible, create array at stack because heap array overheads due to jumping around memory

	// C++11 array
	// original array - there is no direct method to find size of the array
	int a[5]; sizeof(a); // 4*5 = 20 bytes
	int count = sizeof(a) / sizeof(int); // 5
	int* b = new int[5]; sizeof(b); // this is size of the pointer = 4 (so wrong!)
	// Better approach
	static const int size = 5; // use thie for when size is required later
	int sizeKnownArray[size];
	// C++11 style standard array - little bit slower than raw array
	std::array< int, 5 > newArray;
	newArray.size();

	std::cin.get();
}