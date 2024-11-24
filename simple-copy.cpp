#include <iostream>
#include <fstream>
#include <cstdlib>

void copyFileContent(const std::string& sourcePath, const std::string& destinationPath) {
    std::ifstream sourceFile(sourcePath, std::ios::in | std::ios::binary);
    if (!sourceFile.is_open()) {
        std::cerr << "cant open source" << sourcePath << std::endl;
        exit(EXIT_FAILURE);
    }

    std::ofstream destFile(destinationPath, std::ios::out | std::ios::binary);
    if (!destFile.is_open()) {
        std::cerr << "cant open dest" << destinationPath << std::endl;
        sourceFile.close();
        exit(EXIT_FAILURE);
    }

    destFile << sourceFile.rdbuf();

    sourceFile.close();
    destFile.close();

    std::cout << "file copied from" << sourcePath << " to " << destinationPath << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "./simple-copy <source_file> <destination_file>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string sourcePath = argv[1];
    std::string destinationPath = argv[2];

    copyFileContent(sourcePath, destinationPath);

    return EXIT_SUCCESS;
}