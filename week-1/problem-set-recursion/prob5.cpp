/**
 * @file prob5.cpp
 * @brief C++ version of the recursive book-moving example.
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Return true when placing book on target_basket does not break the basket rules.
 * @param book const string& Book to move. The possible values are course names such as Physics and Maths.
 * @param target_basket const vector<string>& Basket that may receive the book. The back element is the current top.
 * @return bool True when the move is allowed, otherwise false.
 */
bool can_place_book(const string& book, const vector<string>& target_basket) {
    if (target_basket.empty()) {
        return true;
    }

    const string& top_book = target_basket.back();
    if (book == "Physics" && top_book == "Chemistry") {
        return false;
    }
    if ((book == "Physics" || book == "Chemistry") && top_book == "Maths") {
        return false;
    }
    return true;
}

/**
 * @brief Recursively transfer n books from one basket to another.
 * @param n int Number of books from the top of source to move.
 * @param source vector<string>& Basket that currently stores the books to move.
 * @param target vector<string>& Basket that should receive the moved books.
 * @param helper vector<string>& Temporary basket used during recursion.
 * @param source_name const string& Label of the source basket in the output.
 * @param target_name const string& Label of the target basket in the output.
 * @param helper_name const string& Label of the helper basket in the output.
 * @return void This function updates the basket contents in place and prints each move.
 */
void transfer_books(int n,
                    vector<string>& source,
                    vector<string>& target,
                    vector<string>& helper,
                    const string& source_name,
                    const string& target_name,
                    const string& helper_name) {
    if (n == 0) {
        return;
    }

    transfer_books(n - 1, source, helper, target, source_name, helper_name, target_name);

    string book = source.back();
    if (!can_place_book(book, target)) {
        throw runtime_error("Invalid move for the basket rules");
    }
    source.pop_back();
    target.push_back(book);
    cout << "Move " << book << " from " << source_name << " to " << target_name << '\n';

    transfer_books(n - 1, helper, target, source, helper_name, target_name, source_name);
}

/**
 * @brief Print the recursive moves for the simplified Hanoi-style book puzzle.
 * @param num_books int Number of books to move.
 * @param source const string& Name of the source basket.
 * @param target const string& Name of the target basket.
 * @param helper const string& Name of the helper basket.
 * @param books const vector<string>& Ordered list of book names used when printing each move.
 * @return void This function only prints the recursive move order.
 */
void move_books(int num_books,
                const string& source,
                const string& target,
                const string& helper,
                const vector<string>& books) {
    if (num_books == 1) {
        cout << "Move book " << books[num_books - 1] << " from " << source << " to " << target << '\n';
        return;
    }

    move_books(num_books - 1, source, helper, target, books);
    cout << "Move book " << books[num_books - 1] << " from " << source << " to " << target << '\n';
    move_books(num_books - 1, helper, target, source, books);
}

/**
 * @brief Print a basket in bracket form.
 * @param basket const vector<string>& Basket contents where each value has type string.
 * @return void This helper only prints data and does not return a value.
 */
void print_basket(const vector<string>& basket) {
    cout << '[';
    for (size_t index = 0; index < basket.size(); ++index) {
        cout << basket[index];
        if (index + 1 != basket.size()) {
            cout << ", ";
        }
    }
    cout << ']';
}

/**
 * @brief Run the book-moving demonstrations.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<string> source = {"Physics", "Chemistry", "Maths"};
    vector<string> target;
    vector<string> helper;

    transfer_books(static_cast<int>(source.size()), source, target, helper, "source", "target", "helper");
    print_basket(source);
    cout << '\n';
    print_basket(target);
    cout << "\n\n";

    vector<string> books = {"Maths", "Chemistry", "Physics"};
    move_books(3, "basket 1", "basket 2", "basket 3", books);
    return 0;
}
