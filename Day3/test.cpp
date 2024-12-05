#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::regex pattern("^.*&"); // Matches the entire first line
        std::smatch match;

        if (std::regex_search(line, match, pattern)) {
            std::cout << "First line: " << match.str() << std::endl;
        } else {
            std::cout << "No match found in the first line." << std::endl;
        }
    } 
    if (!getline(file, line)){
        std::cerr << "Error reading file." << std::endl;
    }

    file.close();

    return 0;
}
