#ifndef __FSUTIL_HPP
#define __FSUTIL_HPP

#include <string>
#include <vector>

std::vector<std::string> all_fais(void);
std::vector<std::string> all_fasta(void);
std::string readTextFile(const std::string& filePath);
#endif