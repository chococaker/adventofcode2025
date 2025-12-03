#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    std::string s = str;
    size_t pos = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        tokens.push_back(s.substr(0, pos));
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s); // Add the last token
    return tokens;
}

bool hasRepeating(const std::string& s) {
    if ((s.length() % 2) != 0) return false;

    std::string start = s.substr(0, s.length() / 2);
    std::string end = s.substr(s.length() / 2);

    return start == end;
}

int main() {
    std::ifstream input("input.txt");

    std::string line;

    std::getline(input, line);

    std::vector<std::string> idRanges = split(line, ",");

    uint64_t idSum = 0;

    for (const std::string& idRange : idRanges) {
        std::vector<std::string> idSplit = split(idRange, "-");
        uint64_t start = std::stoull(idSplit[0]);
        uint64_t end = std::stoull(idSplit[1]);

        for (uint64_t i = start; i <= end; i++) {
            if (hasRepeating(std::to_string(i))) idSum += i;
        }
    }

    std::cout << idSum << std::endl;
}
