"""Maze example.

This file belongs to the week 3 lecture examples on graphs, backtracking, and
divide-and-conquer algorithms. It searches for a path through a maze using
recursive backtracking.
"""

maze = [
    [1, 1, 1, 0, 1],
    [1, 0, 1, 0, 1],
    [1, 0, 1, 1, 1],
    [1, 0, 0, 0, 1],
    [1, 1, 1, 1, 1],
]


def get_neighbors(maze, position):
    """Return every open neighbour around the current cell.

    Args:
        maze (object): The maze input used by this function.
        position (object): The position input used by this function.

    Returns:
        list: The list produced by the algorithm.
    """
    row, col = position
    neighbors = []

    if row > 0 and maze[row - 1][col] == 1:
        neighbors.append((row - 1, col))
    if row < len(maze) - 1 and maze[row + 1][col] == 1:
        neighbors.append((row + 1, col))
    if col > 0 and maze[row][col - 1] == 1:
        neighbors.append((row, col - 1))
    if col < len(maze[0]) - 1 and maze[row][col + 1] == 1:
        neighbors.append((row, col + 1))

    return neighbors


def find_path(maze, start, end, path=None):
    """Use backtracking to search for a path through the maze.

    Args:
        maze (object): The maze input used by this function.
        start (object): The start input used by this function.
        end (object): The end input used by this function.
        path (list): The current path being built by the algorithm.

    Returns:
        object: The value produced by this function.
    """
    if path is None:
        path = []

    path.append(start)

    if start == end:
        return path.copy()

    for neighbor in get_neighbors(maze, start):
        if neighbor not in path:
            result = find_path(maze, neighbor, end, path)
            if result is not None:
                return result

    path.pop()
    return None


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    start = (0, 0)
    end = (4, 4)
    path = find_path(maze, start, end)

    if path:
        print("Path found:", path)
    else:
        print("No path found.")


if __name__ == "__main__":
    main()
