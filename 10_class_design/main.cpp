#include <iostream>
#define Log(x) std::cout << x << std::endl;

class LogSystem {
public:
	const int LogLevelError = 0;
	const int LogLevelInfo = 1;
private: // usually member variable is set to private, to retrieve variable outside, use public methods
	int m_loglevel; // use m prefix to show that variable is member
public:
	int GetLevel() { // retrieve member variable using Get*() methods
		return m_loglevel;
	}
	
	void SetLevel(int level) { // update member variable using Set*() methods
		m_loglevel = level;
	}

	void Error(const char* message) {
		if (m_loglevel >= LogLevelError) 
			std::cout << "[ERROR]: " << message << std::endl;
	}

	void Info(const char* message) {
		if (m_loglevel >= LogLevelInfo)
			std::cout << "[INFO]: " << message << std::endl;
	}
};

int main() {
	LogSystem log;
	log.SetLevel(log.LogLevelError);
	log.Error("Error!");
	log.Info("Info!"); // info log not printed as level set to LogLevelError
	std::cin.get();
}