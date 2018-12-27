#include "ReadManager.hpp"

ReadManager::ReadManager() {

}

ReadManager::ReadManager(ReadManager const &f) {
	*this = f;
}

ReadManager::~ReadManager() {
}

ReadManager & ReadManager::operator=(ReadManager const &readManager) {
	this->inputBuffer = readManager.inputBuffer;
	return (*this);
}

void ReadManager::readFile(std::string fileName) {
	std::ifstream file(fileName);
	std::string line;

	while (std::getline(file, line)) {
		inputBuffer.push_back(line);
	}
	file.close();
}

void ReadManager::printBuffer() {
	for (unsigned long i = 0; i < inputBuffer.size(); i++) {
		std::cout << inputBuffer[i] << "\n";
	}
}