#include "VirtualMachine.hpp"

void runVm(char *fileName) {
	std::cout << "file name" << fileName << "\n";
}

int main(int argc, char **argv) {
	if (argc > 2) {
		std::cout << "Usage: ./avm or ./avm fileName";
	}
	else if (argc == 2) {
		std::cout << "file input" << "\n";
		runVm(argv[1]);
	}
	else {
		std::cout << "standart input" << "\n";
	}
}