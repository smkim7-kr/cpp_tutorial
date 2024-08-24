// virtual functions: overwrite methods in subclass
#include <iostream>
#define Log(x) std::cout << x << std::endl;

class Robot {
public:
	std::string GetName() { return "Robot"; }

};

class NameRobot : public Robot {
private:
	std::string m_Name;
public:
	NameRobot(const std::string& name) {
		m_Name = name;
	}

	std::string GetName() { return m_Name; }
};

class Robot2 {
public:
	virtual std::string GetName() { return "Robot"; } // to overwrite function, make base class function virtual

};

class NameRobot2 : public Robot2 {
private:
	std::string m_Name;
public:
	NameRobot2(const std::string& name) {
		m_Name = name;
	}

	std::string GetName() override { return m_Name; } // not necessary, but let programmer to realize the function is overrided
};
int main() {
	Robot* r = new Robot();
	NameRobot* nr = new NameRobot("AlphaGo");
	Log(r->GetName());
	Log(nr->GetName());

	Robot* r2 = nr;
	Log(r2->GetName()); // GetName() defined on Robot class will be called, but r2 is instance of NameRobot class (nr)!
	
	// virtual function - two (not very large) additional runtime costs (additional memory to create v table, table to check mapping)
	Robot2* vr = new Robot2();
	NameRobot2* vnr = new NameRobot2("AlphaGo");
	Robot2* vr2 = vnr;
	Log(vr2->GetName()); // this returns AlphaGo!
	std::cin.get();
}