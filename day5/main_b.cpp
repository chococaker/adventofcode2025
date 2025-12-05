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

    uint64_t size() const {
        return end - start + 1;
    }
};

int main() {
    std::ifstream input("input.txt");

    std::string line;
    uint64_t val = 0;

    std::vector<Range> ranges;

    while (std::getline(input, line)) {
        if (line.empty()) break;

        size_t dashIndex = line.find("-");

        if (dashIndex == std::string::npos) {
            continue;
        } else {
            Range range = {
                std::stoull(line.substr(0, dashIndex)),
                std::stoull(line.substr(dashIndex + 1))
            };

            ranges.push_back(range);
        }
    }

    // adjust overlapping ranges (brute force)
    // this is actually an interesting problem, i'll come back to it later

    bool isValid = false;
    while (!isValid) {
        isValid = true;

        for (int i = 0; i < ranges.size(); i++) {
            Range& adjusted = ranges[i];

            for (int j = 0; j < ranges.size(); j++) {
                if (i == j) continue;

                Range& adjuster = ranges[j];

                bool containsStart = adjusted.contains(adjuster.start);
                bool containsEnd = adjusted.contains(adjuster.end);

                if (containsStart && containsEnd) { // fully contained range; just remove
                    ranges.erase(ranges.begin() + j);
                    isValid = false;
                } else if (adjusted.contains(adjuster.end) && !adjusted.contains(adjuster.start)) {
                    adjusted.start = adjuster.start;
                    ranges.erase(ranges.begin() + j);
                    isValid = false;
                } else if (adjusted.contains(adjuster.start) && !adjusted.contains(adjuster.end)) {
                    adjusted.end = adjuster.end;
                    ranges.erase(ranges.begin() + j);
                    isValid = false;
                }

                if (!isValid) break;
            }
            if (!isValid) break;
        }
    }

    for (const Range& range : ranges) {
        val += range.size();
    }
    
    std::cout << val << std::endl;
}
