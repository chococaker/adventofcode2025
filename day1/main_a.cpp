#include <iostream>
#include <fstream>
#include <string>

int shift(int dir, int val, int amount) {
    for (int i = 0; i < amount; i++) {
        val += dir;
        if (val == 100) val = 0;
        if (val == -1) val = 99;
    }

    return val;
}

int main() {
    std::ifstream input("input.txt");

    std::string line;
    int val = 50;

    int zeroTimes = 0;

    while (std::getline(input, line)) {
        int dir = line[0] == 'R' ? 1 : -1;
        int amount = std::stoi(line.substr(1));
        val = shift(dir, val, amount);

        if (val == 0) zeroTimes++;
    }

    std::cout << zeroTimes << std::endl;
}
