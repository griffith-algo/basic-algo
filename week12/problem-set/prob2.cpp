/**
 * @file prob2.cpp
 * @brief Console-based C++ version of the QuickHull example.
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

using Point = pair<int, int>;

/**
 * @brief Return which side of a line a point lies on.
 * @param p1 const Point& First endpoint of the line.
 * @param p2 const Point& Second endpoint of the line.
 * @param p const Point& Point being tested.
 * @return int 1 when p is on one side, -1 when p is on the other side, and 0 when it lies on the line.
 */
int findSide(const Point& p1, const Point& p2, const Point& p) {
    int value = (p.second - p1.second) * (p2.first - p1.first) -
                (p2.second - p1.second) * (p.first - p1.first);
    if (value > 0) {
        return 1;
    }
    if (value < 0) {
        return -1;
    }
    return 0;
}

/**
 * @brief Return a value proportional to the distance from a point to a line.
 * @param p1 const Point& First endpoint of the line.
 * @param p2 const Point& Second endpoint of the line.
 * @param p const Point& Point being measured.
 * @return double Absolute line-distance value used by QuickHull.
 */
double lineDist(const Point& p1, const Point& p2, const Point& p) {
    return abs((p.second - p1.second) * (p2.first - p1.first) -
               (p2.second - p1.second) * (p.first - p1.first));
}

/**
 * @brief Recursively collect the boundary points of the convex hull.
 * @param points const vector<Point>& All input points.
 * @param p1 const Point& First endpoint of the current dividing line.
 * @param p2 const Point& Second endpoint of the current dividing line.
 * @param side int Side of the line that the recursive call should inspect.
 * @param hull_points set<Point>& Set that accumulates hull points.
 * @return void This function updates hull_points and does not return a value.
 */
void quickHull(const vector<Point>& points, const Point& p1, const Point& p2, int side, set<Point>& hull_points) {
    int farthest_index = -1;
    double max_distance = 0;

    for (int index = 0; index < static_cast<int>(points.size()); ++index) {
        double distance = lineDist(p1, p2, points[index]);
        if (findSide(p1, p2, points[index]) == side && distance > max_distance) {
            farthest_index = index;
            max_distance = distance;
        }
    }

    if (farthest_index == -1) {
        hull_points.insert(p1);
        hull_points.insert(p2);
        return;
    }

    Point farthest_point = points[farthest_index];
    quickHull(points, farthest_point, p1, -findSide(farthest_point, p1, p2), hull_points);
    quickHull(points, farthest_point, p2, -findSide(farthest_point, p2, p1), hull_points);
}

/**
 * @brief Return the convex hull of a point set using QuickHull.
 * @param points const vector<Point>& Input points.
 * @return vector<Point> Hull points sorted lexicographically.
 */
vector<Point> getHull(const vector<Point>& points) {
    if (points.size() < 3) {
        cout << "Convex hull not possible\n";
        return {};
    }

    int min_x = 0;
    int max_x = 0;
    for (int index = 1; index < static_cast<int>(points.size()); ++index) {
        if (points[index].first < points[min_x].first) {
            min_x = index;
        }
        if (points[index].first > points[max_x].first) {
            max_x = index;
        }
    }

    set<Point> hull_points;
    quickHull(points, points[min_x], points[max_x], 1, hull_points);
    quickHull(points, points[min_x], points[max_x], -1, hull_points);
    return vector<Point>(hull_points.begin(), hull_points.end());
}

/**
 * @brief Run the QuickHull demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<Point> points = {
        {1, 3}, {3, 3}, {3, 5}, {4, 5}, {5, 2},
        {6, 3}, {6, 6}, {8, 4}, {9, 1}, {10, 2}
    };
    vector<Point> hull = getHull(points);
    cout << "The points in Convex Hull are:\n";
    for (const auto& point : hull) {
        cout << '(' << point.first << ", " << point.second << ") ";
    }
    cout << '\n';
    return 0;
}
