#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Return n factorial using recursion.
 * @param n int The size value or number of recursive steps used by the function.
 * @return int The integer result produced by the algorithm.
 */
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

/**
 * @brief Return the largest value in the list using recursion.
 * @param numbers const vector<int>& The numbers value used by this function.
 * @param index size_t The index value used by this function.
 * @return int The integer result produced by the algorithm.
 */
int find_max(const vector<int>& numbers, size_t index = 0) {
    if (index + 1 == numbers.size()) {
        return numbers[index];
    }
    return max(numbers[index], find_max(numbers, index + 1));
}

/**
 * @brief Return a reversed copy of the input string using recursion.
 * @param text const string& The text or string processed by the function.
 * @return string The string produced by the algorithm.
 */
string reverse_string(const string& text) {
    if (text.size() <= 1) {
        return text;
    }
    return reverse_string(text.substr(1)) + text.front();
}

/**
 * @brief Reverse a mutable string in place using recursion.
 * @param text string& The text or string processed by the function.
 * @param left int The left-side data or left boundary used by the algorithm.
 * @param right int The right-side data or right boundary used by the algorithm.
 * @return void This function updates data or prints results and does not return a value.
 */
void reverse_inplace(string& text, int left, int right) {
    if (left >= right) {
        return;
    }
    swap(text[left], text[right]);
    reverse_inplace(text, left + 1, right - 1);
}

/**
 * @brief Return the number of rabbit pairs in the Fibonacci-style model.
 * @param n int The size value or number of recursive steps used by the function.
 * @return int The integer result produced by the algorithm.
 */
int rabbit_count(int n) {
    if (n <= 2) {
        return 1;
    }
    return rabbit_count(n - 1) + rabbit_count(n - 2);
}

/**
 * @brief Print the recursive book moves for the simplified puzzle.
 * @param num_books int The num_books value used by this function.
 * @param source const string& The source peg, basket, or container used in the example.
 * @param target const string& The target peg, basket, or value used in the example.
 * @param helper const string& The helper container or label used in the example.
 * @param books const vector<string>& The books value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void move_books(int num_books, const string& source, const string& target,
                const string& helper, const vector<string>& books) {
    if (num_books == 0) {
        return;
    }
    move_books(num_books - 1, source, helper, target, books);
    cout << "Move book " << books[num_books - 1] << " from " << source
         << " to " << target << '\n';
    move_books(num_books - 1, helper, target, source, books);
}

/**
 * @brief Remove punctuation and spaces before the palindrome check.
 * @param text const string& The text or string processed by the function.
 * @return string The string produced by the algorithm.
 */
string clean_text(const string& text) {
    string cleaned;
    for (char ch : text) {
        if (isalnum(static_cast<unsigned char>(ch))) {
            cleaned.push_back(static_cast<char>(tolower(static_cast<unsigned char>(ch))));
        }
    }
    return cleaned;
}

/**
 * @brief Return true when the text reads the same forwards and backwards.
 * @param text const string& The text or string processed by the function.
 * @param left int The left-side data or left boundary used by the algorithm.
 * @param right int The right-side data or right boundary used by the algorithm.
 * @return bool True when the required condition is satisfied, otherwise false.
 */
bool is_palindrome(const string& text, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (text[left] != text[right]) {
        return false;
    }
    return is_palindrome(text, left + 1, right - 1);
}

/**
 * @brief Replace one character with another throughout a string recursively.
 * @param text const string& The text or string processed by the function.
 * @param from_char char The from_char value used by this function.
 * @param to_char char The to_char value used by this function.
 * @return string The string produced by the algorithm.
 */
string replace_recursive(const string& text, char from_char, char to_char) {
    if (text.empty()) {
        return text;
    }
    char first = text.front() == from_char ? to_char : text.front();
    return string(1, first) + replace_recursive(text.substr(1), from_char, to_char);
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    cout << "factorial(5) = " << factorial(5) << '\n';
    cout << "max([5, 10, 3, 8, 1]) = " << find_max({5, 10, 3, 8, 1}) << '\n';

    string text = "hello world";
    cout << "reverse_string: " << reverse_string(text) << '\n';
    reverse_inplace(text, 0, static_cast<int>(text.size()) - 1);
    cout << "reverse_inplace: " << text << '\n';

    cout << "rabbit_count(6) = " << rabbit_count(6) << "\n\n";

    vector<string> books = {"Maths", "Chemistry", "Physics"};
    move_books(static_cast<int>(books.size()), "basket 1", "basket 2", "basket 3", books);
    cout << '\n';

    for (const string& sample : {string("racecar"), string("hello"), string("A man, a plan, a canal, Panama!")}) {
        string cleaned = clean_text(sample);
        cout << sample << " -> " << boolalpha
             << is_palindrome(cleaned, 0, static_cast<int>(cleaned.size()) - 1) << '\n';
    }

    cout << "replace_recursive(\"steve\", 'e', 'a') = "
         << replace_recursive("steve", 'e', 'a') << '\n';
    return 0;
}
