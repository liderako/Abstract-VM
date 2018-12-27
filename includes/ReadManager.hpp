#ifndef READ_MANAGER_HPP
#define READ_MANAGER_HPP

#include <iostream>
#include <fstream>
#include <vector>

class ReadManager {
	private:
		std::vector<std::string> 	inputBuffer;
	public:
		ReadManager(); // canonical
		ReadManager(ReadManager const & f); // canonical
		~ReadManager(); // canonical

		ReadManager & operator=(ReadManager const &f); // canonical

		// [ACTION]
		void read(std::string filename);
		void printBuffer();
};

#endif