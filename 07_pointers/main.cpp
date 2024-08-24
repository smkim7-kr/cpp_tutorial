// instructions, data, variables are all stored in memory
// and pointers are the number which stores memory address
#include <iostream>

int main() {
	// memory address 0 is not a valid address, so same as null
	void* ptr = 0;// void pointer: we just want to hold a memory address, data type is not important
	void* ptr2 = nullptr; void* ptr3 = NULL; // they are also the same

	int var = 8; // memory address of var?
	void* ptr4 = &var; // ptr4 has the memory address of variable var (ptr is a INTEGER value of memory address)
	// can debug memory at debug > windows > memory of VS and search with variable name or memory address
	int* ptr5 = &var; // nothing have been changed here
	double* ptr6 = (double*)&var; // nothing here again! types of pointers doesn't matter! it is just for users' convinience

	// dereferencing - manipulating data using its address
	void* bad_ptr = &var;
	// *ptr = 10; // this will give an error because ptr doesn't know the data type here (void?)
	int* good_ptr = &var;
	*good_ptr = 10;
	std::cout << "var converts from 8 to 10: " << var << std::endl;
	// NOTE: pointer doesn't know the size of referencing data

	// allocate memory on stack and heap
	int stack_var = 8; // variable to stack
	char* buffer = new char[8]; // new keyword - variable to heap, pointer points to first element buffer[0]'s address 
	memset(buffer, 0, 8); // buffer will reserve 8 bytes
	delete[] buffer; // needs to explicitly use delete keyword to free memory (only when created by new keywords)

	char** ptr_buffer = &buffer; // double pointer - pointing to pointer's address

	std::cin.get();
}