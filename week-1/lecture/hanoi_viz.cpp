/**
 * @file hanoi_viz.cpp
 * @brief Console-based C++ equivalent of the VPython Tower of Hanoi animation.
 *
 * The original Python file animates the disks with VPython. This C++ version
 * keeps the same recursive idea, but prints the peg states in the terminal.
 */

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std;

/**
 * @brief Print the three pegs after a move.
 * @param source const vector<int>& Disks on the source peg. Each disk size has type int.
 * @param temp const vector<int>& Disks on the helper peg. Each disk size has type int.
 * @param destination const vector<int>& Disks on the destination peg. Each disk size has type int.
 * @return void This helper only prints data and does not return a value.
 */
void print_state(const vector<int>& source, const vector<int>& temp, const vector<int>& destination) {
    auto print_one = [](const vector<int>& peg, const string& name) {
        cout << name << ": [";
        for (size_t index = 0; index < peg.size(); ++index) {
            cout << peg[index];
            if (index + 1 != peg.size()) {
                cout << ", ";
            }
        }
        cout << ']';
    };

    print_one(source, "source");
    cout << ' ';
    print_one(temp, "temp");
    cout << ' ';
    print_one(destination, "destination");
    cout << '\n';
}

/**
 * @brief Move one disk between pegs and pause briefly so the output is easier to follow.
 * @param disk int Disk number being moved.
 * @param from vector<int>& Peg that currently contains the disk. The element type is int.
 * @param to vector<int>& Peg that will receive the disk. The element type is int.
 * @param from_name const string& Label of the starting peg.
 * @param to_name const string& Label of the destination peg.
 * @param source const vector<int>& Current state of the source peg after the move.
 * @param temp const vector<int>& Current state of the helper peg after the move.
 * @param destination const vector<int>& Current state of the destination peg after the move.
 * @return void This function updates peg contents in place and prints the new state.
 */
void move_disk(int disk,
               vector<int>& from,
               vector<int>& to,
               const string& from_name,
               const string& to_name,
               const vector<int>& source,
               const vector<int>& temp,
               const vector<int>& destination) {
    to.push_back(from.back());
    from.pop_back();
    cout << "Moving disk " << disk << " from " << from_name << " to " << to_name << '\n';
    print_state(source, temp, destination);
    this_thread::sleep_for(chrono::milliseconds(150));
}

/**
 * @brief Recursively solve the Tower of Hanoi puzzle.
 * @param n int Number of disks to move in the current recursive call.
 * @param source vector<int>& Peg that currently stores the top n disks.
 * @param temp vector<int>& Helper peg used during recursion.
 * @param destination vector<int>& Peg that should receive the disks.
 * @param source_name const string& Name of the source peg.
 * @param temp_name const string& Name of the helper peg.
 * @param destination_name const string& Name of the destination peg.
 * @return void This function updates peg contents in place and prints each move.
 */
void toh(int n,
         vector<int>& source,
         vector<int>& temp,
         vector<int>& destination,
         const string& source_name,
         const string& temp_name,
         const string& destination_name) {
    if (n == 0) {
        return;
    }
    toh(n - 1, source, destination, temp, source_name, destination_name, temp_name);
    move_disk(n, source, destination, source_name, destination_name, source, temp, destination);
    toh(n - 1, temp, source, destination, temp_name, source_name, destination_name);
}

/**
 * @brief Run the console version of the animation example.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<int> source = {6, 5, 4, 3, 2, 1};
    vector<int> temp;
    vector<int> destination;

    print_state(source, temp, destination);
    toh(static_cast<int>(source.size()), source, temp, destination, "source", "temp", "destination");
    cout << "All done\n";
    return 0;
}
