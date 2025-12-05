#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>

struct Range {
    uint64_t start;
    uint64_t end;

    bool contains(uint64_t i) const {
        return i >= start && i <= end;
    }
};

int main() {
    std::ifstream input("input.txt");

    std::string line;
    int val = 0;

    std::vector<Range> ranges;

    while (std::getline(input, line)) {
        if (line.empty()) continue;

        size_t dashIndex = line.find("-");

        if (dashIndex == std::string::npos) {
            uint64_t x = std::stoull(line);

            for (const Range& range : ranges) {
                if (range.contains(x)) {
                    val++;
                    break;
                }
            }

            continue;
        } else {
            Range range = {
                std::stoull(line.substr(0, dashIndex)),
                std::stoull(line.substr(dashIndex + 1))
            };

            ranges.push_back(range);
        }
    }
    

    std::cout << val << std::endl;
}
