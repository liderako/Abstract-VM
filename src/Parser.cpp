#include "Parser.hpp"

std::vector<std::string> 	Parser::run(std::string buffer) {
    std::cmatch result;

    std::regex regularCommand("(pop|dump|add|sub|mul|div|mod|print|exit)");
    std::regex regularCommandWithValue("(push|assert)"
                                       "(\\s)"
                                       "(int32|int8|int16)"
                                       "(\\()"
                                       "(-?[\\d]+)"
                                       "(\\))"
                                       "(\\s*)");
    std::regex regularFloatAndDouble("(push|assert)"
                                     "(\\s)(float|double)"
                                     "(\\()"
                                     "(-?[\\d]+\\.[\\d]+)"
                                     "(\\))"
                                     "(\\s*)");
    std::vector<std::string> resultString;

	if (std::regex_match(buffer.c_str(), regularCommandWithValue) == 1) {
	    std::regex_search(buffer.c_str(), result, regularCommandWithValue);
        resultString.push_back(result[1]);
        resultString.push_back(result[3]);
        resultString.push_back(result[5]);
	}
	else if(std::regex_match(buffer.c_str(), regularFloatAndDouble) == 1) {
	    std::regex_search(buffer.c_str(), result, regularFloatAndDouble);
        resultString.push_back(result[1]);
        resultString.push_back(result[3]);
        resultString.push_back(result[5]);
	}
	else if (std::regex_match(buffer.c_str(), regularCommand) == 1) {
        std::regex_search(buffer.c_str(), result, regularCommand);
        resultString.push_back(result[1]);
	}
    return (resultString);
}