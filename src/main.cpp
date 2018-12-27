#include "VirtualMachine.hpp"
#include "ReadManager.hpp"
#include "ValidationManager.hpp"
#include "Parser.hpp"

void execution(ReadManager readManager) {
	VirtualMachine vm;
	ValidationManager validationManager;
	Parser parser;

	validationManager.runValidation(readManager.getInputBuffer());
	parser.run(vm, readManager.getInputBuffer());
}

int main(int argc, char **argv) {
	ReadManager readManager;

	if (argc > 2) {
		std::cout << "Usage: ./avm or ./avm fileName";
		return -1;
	}
	else if (argc == 2) {
		readManager.readFile(argv[1]);
		readManager.printBuffer();
		execution(readManager);
	}
	else {
		readManager.readConsole();
		execution(readManager);
	}
}