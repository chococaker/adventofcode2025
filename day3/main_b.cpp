#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdint>

uint64_t pow10(int n) {
    uint64_t result = 1;
    for (int i = 0; i < n; i++) {
        result *= 10;
    }
    return result;
}

uint64_t maxJoltage(const std::string& batteryLine) {
    uint64_t joltage = 0;

    int prevDigitIdx = -1;
    uint64_t maxDigit = 0;

    for (int i = 12; i > 0; i--) {
        uint64_t mult = pow10(i - 1);

        for (int j = prevDigitIdx + 1; j < batteryLine.length() - i + 1; j++) {
            uint64_t val = static_cast<uint64_t>(batteryLine[j] - '0');
            if (val > maxDigit) {
                maxDigit = val;
                prevDigitIdx = j;
            }
        }

        joltage += maxDigit * mult;
        maxDigit = 0;
    }

    return joltage;
}

int main() {
    std::ifstream input("input.txt");

    std::string line;
    uint64_t val = 0;

    while (std::getline(input, line)) {
        uint64_t max = maxJoltage(line);
        val += max;
    }

    std::cout << val << std::endl;
}
