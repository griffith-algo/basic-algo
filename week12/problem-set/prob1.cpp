/**
 * @file prob1.cpp
 * @brief Console-based C++ version of the closest-pair-of-points example.
 */

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

using Point = pair<double, double>;

/**
 * @brief Return the straight-line distance between two points.
 * @param p1 const Point& First point as (x, y).
 * @param p2 const Point& Second point as (x, y).
 * @return double Euclidean distance between p1 and p2.
 */
double euclidean_distance(const Point& p1, const Point& p2) {
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Merge two sorted point lists using either x or y as the key.
 * @param left const vector<Point>& First sorted half.
 * @param right const vector<Point>& Second sorted half.
 * @param key int Coordinate index: 0 means x, 1 means y.
 * @return vector<Point> Merged sorted list.
 */
vector<Point> merge(const vector<Point>& left, const vector<Point>& right, int key) {
    vector<Point> merged;
    size_t i = 0;
    size_t j = 0;

    while (i < left.size() && j < right.size()) {
        double left_key = key == 0 ? left[i].first : left[i].second;
        double right_key = key == 0 ? right[j].first : right[j].second;
        if (left_key < right_key) {
            merged.push_back(left[i++]);
        } else {
            merged.push_back(right[j++]);
        }
    }
    merged.insert(merged.end(), left.begin() + static_cast<long>(i), left.end());
    merged.insert(merged.end(), right.begin() + static_cast<long>(j), right.end());
    return merged;
}

/**
 * @brief Sort points using merge sort and the selected coordinate as the key.
 * @param points const vector<Point>& Input point list.
 * @param key int Coordinate index: 0 means x, 1 means y.
 * @return vector<Point> Sorted copy of points.
 */
vector<Point> merge_sort(const vector<Point>& points, int key) {
    if (points.size() <= 1) {
        return points;
    }
    size_t middle = points.size() / 2;
    vector<Point> left(points.begin(), points.begin() + static_cast<long>(middle));
    vector<Point> right(points.begin() + static_cast<long>(middle), points.end());
    return merge(merge_sort(left, key), merge_sort(right, key), key);
}

/**
 * @brief Return the closest pair of points using divide and conquer.
 * @param points const vector<Point>& Points sorted by x-coordinate.
 * @param sorted_y const vector<Point>& Same points sorted by y-coordinate.
 * @return pair<pair<Point, Point>, double> Closest pair and the distance between them.
 */
pair<pair<Point, Point>, double> closest_pair(const vector<Point>& points, const vector<Point>& sorted_y) {
    if (points.size() <= 3) {
        double min_distance = 1e18;
        pair<Point, Point> min_pair;
        for (size_t i = 0; i < points.size(); ++i) {
            for (size_t j = i + 1; j < points.size(); ++j) {
                double distance = euclidean_distance(points[i], points[j]);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_pair = {points[i], points[j]};
                }
            }
        }
        return {min_pair, min_distance};
    }

    size_t mid = points.size() / 2;
    vector<Point> left_points(points.begin(), points.begin() + static_cast<long>(mid));
    vector<Point> right_points(points.begin() + static_cast<long>(mid), points.end());

    vector<Point> left_sorted_y;
    vector<Point> right_sorted_y;
    for (const Point& point : sorted_y) {
        bool belongs_to_left = false;
        for (const Point& left_point : left_points) {
            if (left_point == point) {
                belongs_to_left = true;
                break;
            }
        }
        if (belongs_to_left) {
            left_sorted_y.push_back(point);
        } else {
            right_sorted_y.push_back(point);
        }
    }

    auto left_result = closest_pair(left_points, left_sorted_y);
    auto right_result = closest_pair(right_points, right_sorted_y);
    auto best_result = left_result.second < right_result.second ? left_result : right_result;

    vector<Point> strip_points;
    double middle_x = points[mid].first;
    for (const Point& point : sorted_y) {
        if (fabs(point.first - middle_x) < best_result.second) {
            strip_points.push_back(point);
        }
    }

    for (size_t i = 0; i < strip_points.size(); ++i) {
        for (size_t j = i + 1; j < strip_points.size(); ++j) {
            if (strip_points[j].second - strip_points[i].second >= best_result.second) {
                break;
            }
            double distance = euclidean_distance(strip_points[i], strip_points[j]);
            if (distance < best_result.second) {
                best_result = {{strip_points[i], strip_points[j]}, distance};
            }
        }
    }
    return best_result;
}

/**
 * @brief Run the closest-pair demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}, {30, 25}};
    vector<Point> sorted_points = merge_sort(points, 0);
    vector<Point> sorted_y = merge_sort(points, 1);
    auto result = closest_pair(sorted_points, sorted_y);
    cout << "Closest pair: ((" << result.first.first.first << ", " << result.first.first.second << "), ("
         << result.first.second.first << ", " << result.first.second.second << "))\n";
    cout << "Minimum distance: " << result.second << '\n';
    return 0;
}
