#include "ReadManager.hpp"

/* Canonical form */
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

/* ********* */

void ReadManager::readFile(std::string fileName) {
	std::ifstream file(fileName);
	std::string line;

	while (std::getline(file, line)) {
		inputBuffer.push_back(line);
	}
	file.close();
	if (inputBuffer.size() > 0) {
		deleteComment();
	}
}

void ReadManager::readConsole() {
	std::string line;
	while (1) {
		if ( std::getline( std::cin, line ) ) {
			if (line.compare(";;") == 0) {
				break ;
			}
			inputBuffer.push_back(line);
		}
		else {
				std::cout << "Error read input\n";
				std::exit(-1);
		}
	}
	if (inputBuffer.size() > 0) {
		deleteComment();
	}
}

void ReadManager::deleteComment() {
	for (unsigned long i = 0; i < inputBuffer.size(); i++) {
		std::stringstream ss(inputBuffer[i]);
		std::string buff;
		
		while (getline(ss, buff, ';')) {
			inputBuffer[i] = buff;
			break ;
		}
	}
	for (unsigned long i = 0; i < inputBuffer.size(); i++) {
		if ((inputBuffer[i].length()) == 0) {
			inputBuffer.erase(inputBuffer.begin() + i);
			i--;
		}
	}
}

void ReadManager::printBuffer() {
	for (unsigned long i = 0; i < inputBuffer.size(); i++) {
		std::cout << inputBuffer[i] << "\n";
	}
}


std::vector<std::string> 	ReadManager::getInputBuffer() {
	return inputBuffer;
}