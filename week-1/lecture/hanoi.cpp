/**
 * @file hanoi.cpp
 * @brief Console-based C++ version of the Tower of Hanoi list example.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief Print the contents of one peg.
 * @param peg const vector<int>& Stack of disk sizes on the peg. Each value has type int.
 * @param name const string& Label that identifies the peg in the printed output.
 * @return void This helper only prints data and does not return a value.
 */
void print_peg(const vector<int>& peg, const string& name) {
    cout << name << ": [";
    for (size_t index = 0; index < peg.size(); ++index) {
        cout << peg[index];
        if (index + 1 != peg.size()) {
            cout << ", ";
        }
    }
    cout << ']';
}

/**
 * @brief Move a stack of disks from one peg to another using recursion.
 * @param n int Number of disks to move in the current recursive call.
 * @param source vector<int>& Peg that currently stores the top n disks. The element type is int.
 * @param target vector<int>& Peg that should receive the moved disks. The element type is int.
 * @param auxiliary vector<int>& Helper peg used during recursion. The element type is int.
 * @param source_name const string& Name of the source peg shown in the output.
 * @param target_name const string& Name of the target peg shown in the output.
 * @param auxiliary_name const string& Name of the helper peg shown in the output.
 * @return void This function updates the peg contents in place and prints each move.
 */
void hanoi(int n,
           vector<int>& source,
           vector<int>& target,
           vector<int>& auxiliary,
           const string& source_name,
           const string& target_name,
           const string& auxiliary_name) {
    if (n == 0) {
        return;
    }

    hanoi(n - 1, source, auxiliary, target, source_name, auxiliary_name, target_name);

    int disk = source.back();
    source.pop_back();
    target.push_back(disk);

    cout << "Move disk " << disk << " from " << source_name << " to " << target_name << " | ";
    print_peg(source, source_name);
    cout << ' ';
    print_peg(target, target_name);
    cout << ' ';
    print_peg(auxiliary, auxiliary_name);
    cout << '\n';

    hanoi(n - 1, auxiliary, target, source, auxiliary_name, target_name, source_name);
}

/**
 * @brief Run the Tower of Hanoi demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> source = {3, 2, 1};
    vector<int> target;
    vector<int> auxiliary;

    hanoi(static_cast<int>(source.size()), source, target, auxiliary, "source", "target", "auxiliary");
    return 0;
}
