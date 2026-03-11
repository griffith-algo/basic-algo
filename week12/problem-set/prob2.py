"""Prob2 example.

This file belongs to the week 12 geometry and compression examples. It
implements QuickHull and also visualises the result.
"""

import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial import ConvexHull


def findSide(p1, p2, p):
    """Return which side of a line a point lies on.

    Args:
        p1 (tuple): The first point that defines the reference line or distance check.
        p2 (tuple): The second point that defines the reference line or distance check.
        p (tuple): A single point used by the geometry algorithm.

    Returns:
        int: The integer result produced by the algorithm.
    """
    value = (p[1] - p1[1]) * (p2[0] - p1[0]) - (p2[1] - p1[1]) * (p[0] - p1[0])

    if value > 0:
        return 1
    if value < 0:
        return -1
    return 0


def lineDist(p1, p2, p):
    """Return a value proportional to the distance from a point to a line.

    Args:
        p1 (tuple): The first point that defines the reference line or distance check.
        p2 (tuple): The second point that defines the reference line or distance check.
        p (tuple): A single point used by the geometry algorithm.

    Returns:
        float: The numeric result produced by the algorithm.
    """
    return abs((p[1] - p1[1]) * (p2[0] - p1[0]) - (p2[1] - p1[1]) * (p[0] - p1[0]))


def quickHull(points, p1, p2, side, hull_points):
    """Recursively collect the boundary points of the convex hull.

    Args:
        points (list): The points used by the geometry algorithm.
        p1 (tuple): The first point that defines the reference line or distance check.
        p2 (tuple): The second point that defines the reference line or distance check.
        side (object): The side input used by this function.
        hull_points (object): The hull_points input used by this function.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    farthest_index = -1
    max_distance = 0

    for index, point in enumerate(points):
        distance = lineDist(p1, p2, point)
        if findSide(p1, p2, point) == side and distance > max_distance:
            farthest_index = index
            max_distance = distance

    if farthest_index == -1:
        hull_points.add(p1)
        hull_points.add(p2)
        return

    farthest_point = points[farthest_index]
    quickHull(points, farthest_point, p1, -findSide(farthest_point, p1, p2), hull_points)
    quickHull(points, farthest_point, p2, -findSide(farthest_point, p2, p1), hull_points)


def getHull(points):
    """Return the convex hull of the given points using QuickHull.

    Args:
        points (list): The points used by the geometry algorithm.

    Returns:
        list: The list produced by the algorithm.
    """
    if len(points) < 3:
        print("Convex hull not possible")
        return []

    min_x = min(range(len(points)), key=lambda index: points[index][0])
    max_x = max(range(len(points)), key=lambda index: points[index][0])
    hull_points = set()

    quickHull(points, points[min_x], points[max_x], 1, hull_points)
    quickHull(points, points[min_x], points[max_x], -1, hull_points)

    result = sorted(hull_points)
    print("The points in Convex Hull are:")
    print(result)
    return result


def main():
    """Run the small demonstration for this teaching example.

    Returns:
        None: This function updates data or prints results and does not return a value.
    """
    points = [
        (1, 3),
        (3, 3),
        (3, 5),
        (4, 5),
        (5, 2),
        (6, 3),
        (6, 6),
        (8, 4),
        (9, 1),
        (10, 2),
    ]
    hull = getHull(points)

    points_array = np.array(points)
    scipy_hull = ConvexHull(points_array)
    fig, (ax1, ax2) = plt.subplots(ncols=2, figsize=(10, 3))

    for ax in (ax1, ax2):
        ax.plot(points_array[:, 0], points_array[:, 1], ".", color="k")
        if ax is ax1:
            ax.set_title("Given points")
        else:
            ax.set_title("Convex hull")
            for simplex in scipy_hull.simplices:
                ax.plot(points_array[simplex, 0], points_array[simplex, 1], "c")

            hull_array = np.array(hull)
            ax.plot(
                hull_array[:, 0],
                hull_array[:, 1],
                "o",
                mec="r",
                color="none",
                lw=1,
                markersize=10,
            )

        ax.set_xticks(range(11))
        ax.set_yticks(range(7))

    plt.show()


if __name__ == "__main__":
    main()
