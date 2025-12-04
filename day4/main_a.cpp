#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>

bool isForkliftable(const std::vector<std::vector<char>>& map, int row, int col) {
    auto hasPaperRoll = [&](int prow, int pcol) {
        if (prow >= map.size() || pcol >= map[row].size() || prow < 0 || pcol < 0) return false;
        return map[prow][pcol] == '@';
    };

    int spots = 0;
    // another brute-force solution from yours truly
    spots += hasPaperRoll(row - 1, col - 1);
    spots += hasPaperRoll(row - 1, col + 0);
    spots += hasPaperRoll(row - 1, col + 1);
    spots += hasPaperRoll(row + 0, col + 1);
    spots += hasPaperRoll(row + 1, col + 1);
    spots += hasPaperRoll(row + 1, col - 0);
    spots += hasPaperRoll(row + 1, col - 1);
    spots += hasPaperRoll(row - 0, col - 1);

    std::cout << spots << std::endl;

    return spots < 4;
}

int main() {
    std::ifstream input("input.txt");

    std::string line;
    int val = 50;

    std::vector<std::vector<char>> map;

    while (std::getline(input, line)) {
        // parse map
        std::vector<char> lineVec;
        lineVec.reserve(line.size());
        for (char ch : line) {
            lineVec.push_back(ch);
        }

        map.push_back(lineVec);
    }

    int accessiblePlaces = 0;

    for (int row = 0; row < map.size(); row++) {
        for (int col = 0; col < map[row].size(); col++) {
            if (map[row][col] == '@' && isForkliftable(map, row, col)) {
                accessiblePlaces++;
            }
        }
    }

    std::cout << accessiblePlaces << std::endl;
}
