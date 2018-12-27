#include "VirtualMachine.hpp"
#include "ReadManager.hpp"

void runVm(char *fileName) {
	std::cout << "file name" << fileName << "\n";
}

int main(int argc, char **argv) {
	if (argc > 2) {
		std::cout << "Usage: ./avm or ./avm fileName";
	}
	else if (argc == 2) {
		ReadManager readManager;
		readManager.readFile(argv[1]);
		readManager.printBuffer();
	}
	else {
		std::cout << "standart input" << "\n";
	}
}