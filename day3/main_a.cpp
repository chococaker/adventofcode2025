#include <iostream>
#include <fstream>
#include <string>

int maxJoltage(const std::string& batteryLine) {
    int maxLargeDigit = 0;
    int maxLargeDigitIdx = 0;

    for (int i = 0; i < batteryLine.length() - 1; i++) {
        int val = batteryLine[i] - '0';
        if (batteryLine[i] - '0' > maxLargeDigit) {
            maxLargeDigit = val;
            maxLargeDigitIdx = i;
        }
    }

    int maxSmallDigit = 0;
    int maxSmallDigitIdx = 0;

    for (int i = maxLargeDigitIdx + 1; i < batteryLine.length(); i++) {
        int val = batteryLine[i] - '0';
        if (batteryLine[i] - '0' > maxSmallDigit) {
            maxSmallDigit = val;
            maxSmallDigitIdx = i;
        }
    }

    return maxLargeDigit * 10 + maxSmallDigit;
}

int main() {
    std::ifstream input("input.txt");

    std::string line;
    int val = 0;

    while (std::getline(input, line)) {
        int max = maxJoltage(line);
        val += max;
    }

    std::cout << val << std::endl;
}
