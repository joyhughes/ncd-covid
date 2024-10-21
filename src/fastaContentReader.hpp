#ifndef FASTA_CONTENT_FETCHER_HPP
#define FASTA_CONTENT_FETCHER_HPP
#include "fileContentReader.hpp"

class FastaContentReader final : public FileContentReader {
public:
    std::string read(const std::string& filePath) override;
};

#endif
