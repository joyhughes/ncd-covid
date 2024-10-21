#include <vector>
#include <fsutil.hpp>
#include <iostream>
#include <__filesystem/directory_iterator.h>

#include "fastaContentReader.hpp"
#include "fileContentReader.hpp"
#include "ncdHelper.hpp"


#include "fastaContentReader.hpp"
#include "fsutil.hpp"
#include "fileContentReader.hpp"
namespace fs = std::filesystem;

void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            std::cout << std::setw(10) << std::setprecision(4) << value << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <folder_path>" << std::endl;
        return 1;
    }
    const std::string folder = argv[1];
    FileReaderContext fileReaderContext;
    fileReaderContext.setContentReader(std::make_unique<FastaContentReader>());
    std::vector<std::string> sequences;
    for(const auto& entry: fs::directory_iterator(folder)) {
        if (entry.is_regular_file()) {
            const std::string filePath = entry.path();
            const std::string content = readTextFile(filePath);
            const std::string sequence = fileReaderContext.read(content);
            sequences.push_back(sequence);
        }
    }
    const unsigned int size = sequences.size();
    std::vector<std::vector<double>> matrix = NCDHelper::instance().getNCD(sequences);
    std::cout << "NCD " << size  << "x"  << size << " matrix from src folder: " << folder;
    printMatrix(matrix);
    exit(0);
}

