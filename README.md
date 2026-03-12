# Basic Algorithms Teaching Repository

This repository contains beginner-friendly examples for algorithms, recursion,
data structures, graph problems, dynamic programming, and introductory
algorithm analysis. The material is organised by teaching week, and the code is
written to be read by bachelor students who are still learning how to trace,
modify, and compare algorithms.

## What Is In This Repository

Each teaching example now has:

- a Python version (`*.py`) used in the original class material
- a matching C++ version (`*.cpp`) with the same stem and placed in the same folder
- explanatory module comments and function-level documentation aimed at new learners

Example:

- `week-1/lecture/gcd.py`
- `week-1/lecture/gcd.cpp`
- `week-2/problem-set/prob_10_shares.py`
- `week-2/problem-set/prob_10_shares.cpp`

This one-file-per-example layout makes it easier to compare the same algorithm
across Python and C++ without searching through combined teaching files.

## Folder Structure

- `week-1`
  Introductory recursion, Euclid's algorithm, Tower of Hanoi, prime generation,
  and early problem-set exercises.
- `week-2`
  Searching, linked structures, queues, stacks, graph representations, and
  priority queues.
- `week-3`
  Graphs, maze backtracking, travelling salesperson, sorting, greedy methods,
  and dynamic programming.
- `week-4`
  Divide-and-conquer and memoization examples.
- `week-5`
  Sorting algorithms and heap exercises.
- `week-7&8`
  Binary trees, binary search trees, heaps, and hashing.
- `week-9&10`
  Spanning-tree algorithms.
- `week11`
  Pattern matching, longest common subsequence, and edit distance.
- `week12`
  Computational geometry and Huffman coding.

## Naming Convention

For every Python example, the C++ translation uses the same file stem.

- `prob1.py` -> `prob1.cpp`
- `maze.py` -> `maze.cpp`
- `selection-sort.py` -> `selection-sort.cpp`

This is intentional so students can keep one Python file and one C++ file open
side by side.

## How To Study From This Repository

A good workflow for beginners is:

1. Read the file-level comment at the top of the Python or C++ example.
2. Read the function documentation before reading the function body.
3. Trace the algorithm on a very small input by hand.
4. Run the example and compare the output with your manual trace.
5. Change one input at a time to see how the algorithm behaves.
6. Compare the Python and C++ versions to understand language differences.

## Running Python Files

Run a single Python example with:

```bash
python week-1/lecture/gcd.py
```

If a file uses a third-party library such as `matplotlib`, `pygame`,
`networkx`, `numpy`, `scipy`, or `vpython`, that library must be installed in
your Python environment first.

## Running C++ Files

Compile and run one C++ example with:

```bash
g++ -std=c++17 week-1/lecture/gcd.cpp -o gcd
./gcd
```

Another example:

```bash
g++ -std=c++17 week-2/problem-set/prob_10_shares.cpp -o prob_10_shares
./prob_10_shares
```

## Notes About The C++ Versions

- Each `*.cpp` file is a direct teaching counterpart to one `*.py` file.
- The C++ examples use console output by default so they stay easy to compile
  and run.
- When the original Python file used a graphical library, the C++ version uses
  a console-based equivalent instead of a graphics dependency.
- The comments in the C++ files explain function purpose, parameter meaning,
  data types, and return values.

## Suggested Use In Class Or Self-Study

You can use the repository in several ways:

- read only the Python versions first if you are new to programming
- read Python and C++ side by side if you are learning both languages
- use the C++ versions for practice translating algorithm ideas into a typed language
- modify the sample inputs and observe how the output changes

## Verification

A full repository check can be done with:

```bash
python -m compileall -q .
find . -name '*.cpp' -print0 | xargs -0 -n1 g++ -std=c++17 -fsyntax-only
```

## Audience

The repository is written for students who are still learning:

- variables and data types
- conditionals and loops
- functions and return values
- arrays, lists, stacks, queues, trees, and graphs
- basic algorithmic thinking and tracing

The examples are intentionally small so one idea can be studied at a time.
