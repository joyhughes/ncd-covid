#include "fastaContentReader.hpp"

#include <fstream>

std::string FastaContentReader::read(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }
    std::string line;
    std::string sequence;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        if (line[0] == '>') {
            continue;
        }
        sequence += line + "\n";
    }
    return sequence;
}
