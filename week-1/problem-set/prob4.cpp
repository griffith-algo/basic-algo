/**
 * @file prob4.cpp
 * @brief C++ version of the decimal-to-binary example.
 */

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Convert a decimal integer to a binary string.
 * @param decimal int Non-negative integer to convert to base 2.
 * @return string Binary representation of decimal.
 */
string decimal_to_binary(int decimal) {
    if (decimal == 0) {
        return "0";
    }

    string binary;
    while (decimal > 0) {
        int remainder = decimal % 2;
        binary.push_back(static_cast<char>('0' + remainder));
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

/**
 * @brief Run the decimal-to-binary demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    int decimal = 128;
    cout << decimal_to_binary(decimal) << '\n';
    return 0;
}
