#ifndef READ_MANAGER_HPP
#define READ_MANAGER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


class ReadManager {
	private:
		std::vector<std::string> 	inputBuffer;
    class ExceptionFileDoesntExists : public std::exception {
        public:
            ExceptionFileDoesntExists();
            const char * what() const throw();
            ~ExceptionFileDoesntExists() throw() {}
        };
	public:
		ReadManager(); // canonical
		ReadManager(ReadManager const & f); // canonical
		~ReadManager(); // canonical

		ReadManager & operator=(ReadManager const &f); // canonical

		// [ACTION]
		void readFile(std::string filename);
		void readConsole();
		void deleteComment();


		std::vector<std::string> 	getInputBuffer();
};

#endif