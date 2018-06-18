#include "CommonUtils.h"
#include <iostream>

std::string getFilenameExtension(std::string filename) {
	auto last_point = filename.find_last_of(".");
	if (last_point == std::string::npos) {
		std::cerr << "[ERROR] Specified file \"" << filename << "\" has no extension!" << std::endl;
		exit(EXIT_FAILURE);
	}

	return filename.substr(last_point + 1);
}
