#ifndef FILE_CONTENT_READER_HPP
#define FILE_CONTENT_READER_HPP

#include <string>
#include <stdexcept>

class FileContentReader {
public:
    virtual ~FileContentReader() = default;
    virtual std::string read(const std::string& filePath) = 0;
};

class FileReaderContext {
    std::unique_ptr<FileContentReader> contentReader;

public:
    void setContentReader(std::unique_ptr<FileContentReader> contentReader) {
        this->contentReader = std::move(contentReader);
    }

    [[nodiscard]] std::string read(const std::string& filePath) const {
        if (!contentReader) {
            throw std::runtime_error("File content fetcher is not set");
        }
        return contentReader->read(filePath);
    }
};

#endif