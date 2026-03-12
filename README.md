# Data Structures and Algorithms

This repository contains weekly teaching examples and problem-set solutions for
`2801ICT` and `7011ICT`. The material is organised by week and is intended for
students who are new to algorithms, recursion, data structures, graph
algorithms, dynamic programming, and introductory algorithm analysis.

The codebase now includes:

- Python examples with beginner-friendly module docstrings and function
  docstrings.
- Clearer worked examples where the original code was incomplete or confusing.
- C++ translations for the teaching material, added as grouped examples inside
  each topic folder.
- A refreshed week 5 sorting notebook that matches the cleaned Python scripts.

## Repository Layout

Each folder contains lecture material, problem-set code, or both.

- `week-1`
  Introductory recursion, Euclid's algorithm, prime generation, search
  examples, and basic algorithm puzzles.
- `week-2`
  Searching, queues, stacks, graph representations, priority queues, and
  introductory data-structure exercises.
- `week-3`
  Graphs, maze backtracking, travelling salesperson examples, sorting, greedy
  algorithms, and dynamic programming.
- `week-4`
  Divide-and-conquer and memoization examples.
- `week-5`
  Sorting algorithms, a notebook version of the sorting material, and heap
  checks.
- `week-7&8`
  Binary trees, binary search trees, heaps, and hashing examples.
- `week-9&10`
  Spanning-tree examples.
- `week11`
  Pattern matching, longest common subsequence, and edit distance.
- `week12`
  Computational geometry and Huffman coding.

## File Types

- `*.py`
  The main teaching scripts used in the course.
- `*.cpp`
  Grouped C++ equivalents of the Python material for students comparing Python
  and C++.
- `*.ipynb`
  Notebook-based walkthroughs for selected topics.
- `*.pptx`, `*.gif`, `*.png`
  Lecture slides and visual support material.

## How To Use This Repository

1. Start with the lecture folders for the week you are studying.
2. Read the docstrings before reading the body of each function.
3. Run the Python or C++ examples with small inputs first.
4. Move to the problem-set folders once you understand the lecture examples.
5. Compare the Python and C++ versions when you want to see how the same
   algorithm looks in both languages.

## Running The Code

### Python

Run a single file with:

```bash
python week-1/lecture/gcd.py
```

### C++

Compile and run a C++ example with:

```bash
g++ -std=c++17 week-5/lecture/1-selection-sort/selection-sort.cpp -o selection-sort
./selection-sort
```

## Recommended Background

Students will get the most value from this repository if they are familiar
with:

- Variables and basic data types.
- `if` statements and loops.
- Functions and return values.
- Lists, arrays, and basic indexing.

No advanced background is assumed for most week 1 to week 3 content.

## Notes About The Examples

- Some Python lecture files use external libraries such as `matplotlib`,
  `pygame`, `networkx`, `numpy`, `scipy`, or `vpython`.
- The C++ translations are console-based when the original Python example used
  graphics or plotting.
- Several files are intentionally short because they are meant to highlight one
  algorithmic idea at a time.
- The `main()` blocks are small demonstrations, not full test suites.

## Suggested Study Workflow

For each week:

1. Read the problem statement or lecture topic first.
2. Trace the example by hand with a very small input.
3. Run the code and compare the output with your trace.
4. Change one input at a time and observe what the algorithm does.
5. Try reimplementing the idea yourself before checking the provided solution.

## Verification

The repository has been checked with:

- `python -m compileall -q .`
- `g++ -std=c++17 -fsyntax-only` on all generated `*.cpp` files

## License

See [LICENSE](/mnt/win_d/2801ict-2024-old/LICENSE).
