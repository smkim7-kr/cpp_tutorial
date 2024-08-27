This is a C++ tutorial based on [The Cherno C++ Playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

| tutorial                        | tl;dr                                                        |
| ------------------------------- | ------------------------------------------------------------ |
| 01_variables                    | variables have diverse data types - int, float, bool etc.<br />*int var = 20; char a = 65;* |
| 02_functions                    | functions are useful when to use modularize the code or when repeated codes exists<br />*int Product(int a, int b) {}* |
| 03_header_files                 | ".h" header files have declaration of functions<br />*#pragma once ... void Log(const char\* message);* |
| 04_conditions                   | conditions and branching jumps different areas of memory, thus there are overheads<br />*if (ptr) {...} else if {...} else {...}* |
| 05_loops                        | while and for - when same codes are required to be executed multiple times<br />*for (int i = 0; i < 5; ++i) {...}* |
| 06_control_flow                 | continue, break, return - determine when to end a loop/function<br />*for (int i = 0; i < 5; ++i) {...break...continue...}* |
| 07_pointers                     | pointers are the number which stores memory address; types of pointers doesn't matter!<br />*int var = 8; int\* ptr = &var;* |
| 08_references                   | references does not occupy extra memory unlike pointers, it needs to reference existing variable<br />*void Increment(int& value) {...}* |
| 09_class_structs                | class and structs are ways to group data and functionality, and useful for object-oriented programming<br />*class Player {int x, y;}; struct s_Player {int x, y;};* |
| 10_class_design                 | set member variables private, retrieve/update member variables by public Get()/Set() methods<br />*class LogSystem { private: int m_x; public: int GetX() { return m_x; } };* |
| 11_static                       | static keyword is used to declare variable/function that is visible to current file. When static keyword is used inside class/struct, it's are shared by all class/struct instances<br />*struct s_Robot { static int x; } int s_Robot::x;* |
| 12_enums                        | enums group variables with logical sense<br />*enum Choice { A, B, C }; Choice::B;* |
| 13_constructors_destructors     | constructor/destructor is a special type of function when instantiating/destroying the object<br />*class Robot { int m_x; Robot() { m_x = 0; }; ~Robot() {} };* |
| 14_inheritance                  | inheritance creates hierarchy of classes, inherited class can access non-private members/methods of parent classes<br />*class Robot { ... }; class NameRobot : public Robot { ... };* |
| 15_virtual_functions            | to overwrite function of child class, base class function need to be virtual; virtual functions takes computational overhead<br />*class Robot { virtual int GetX() {...} }* |
| 16_interfaces                   | interface is a special types of virtual functions - "pure virtual functions'; force subclass to implement a method<br />*class Robot { virtual int GetX() = 0; }* |
| 17_visibility                   | visibility is a tool programmers to determine the scope of authority of methods/members; 3 types - private, protected, public<br />*class R { protected: int pX; }; class CR : public R { CR() { pX  = 10; } };* |
| 18_arrays                       | arrays are collection of variables stored in contiguous memory, usually in same type; array is a pointer<br />*int arr[5]; int\* arr2 = arr; std::array<int , 5> arr3; arr3.size();* |
| 19_strings                      | string is array of characters<br />*const char\* cstyle = "foo"; char strarr[4] = {'f','o','o','\0}; std::string best = "foo";* |
| 20_string_literals              | string literals are by default const char[] data type (use array to avoid const constraint); they are stored in read-only memory<br />*char name[4] = "foo"; const char\* name2 = "foo";* |
| 21_const                        | const is a keyword that signals variable/function/pointer address cannot be changed; const before/after \* cannot change the value/address<br />*const int a = 5; const int\* const b = 10; int func() const {}* |
| 22_mutable                      | mutable variable can be changed in the const function<br />*mutable int x = 1; int func() const { x = 10; }* |
| 23_constructor_initializer_list | initializing member variables using constructor initializer list has better performance than initializing inside methods<br />*Constructor() : m_x(0), m_y(0) {}* |
| 24_ternary_operators            | ternary operators can simplify branching expressions<br />*int a = 8; int b = a > 5 ? 10 : 5;* |
| 25_instantiate_objects          | If possible, instantiate objects on stack rather than heap; stack objects live in scope, heap objects need to be destroyed explicitly<br />*Class\* hr = new Class(); { Class sr; } delete hr;* |
| 26_new                          | whenever new keyword is used, computer should find continuous memory of object size in the heap, so it takes overhead; placement new operator prevents allocating new memory<br />*int\* arr = new int[50]; int\* arr2 = new(arr) int;* |
| 27_implicit_explicit            | explicit constructors cannot take implicit conversions<br />(implicit) *Class c(0); Class c2 = {0}; func({0});*<br />(explicit) *Class e(10)* is only accepted instantiation format |
| 28_operators                    | operator includes new, \*, +, <<; overload operator redefine the behavior of operator, use overloading minimally<br />*ClassInt operator+(const ClassInt& y) const { return ClassInt(this->val + y.val); }* |
| 29_this                         | this keyword of the class is the address of current object<br />*class C{ int m_x = 0; C(int x) {this->m_x = x} };* |
| 30_object_lifetime              | stack-based object is destroyed when scope {} ends; use unique pointer to automatically deleted heap-based object out of scope<br />*{ Class c; Class\* c2 = new Class(); }*  => class c destroyed out of this scope |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |
|                                 |                                                              |