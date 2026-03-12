/**
 * @file prob7.cpp
 * @brief C++ version of the same-circumference geometry example.
 */

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/**
 * @brief Determine whether all points lie on the same circumference.
 * @param points const vector<pair<double, double>>& List of 2D points where each point stores x and y coordinates.
 * @return bool True when every point lies on the same circle, otherwise false.
 */
bool on_same_circumference(const vector<pair<double, double>>& points) {
    if (points.size() < 3) {
        return true;
    }

    double x1 = points[0].first;
    double y1 = points[0].second;
    double x2 = points[1].first;
    double y2 = points[1].second;
    double x3 = points[2].first;
    double y3 = points[2].second;

    double a = (x1 * x1 + y1 * y1) * (y2 - y3) +
               (x2 * x2 + y2 * y2) * (y3 - y1) +
               (x3 * x3 + y3 * y3) * (y1 - y2);
    double b = (x1 * x1 + y1 * y1) * (x3 - x2) +
               (x2 * x2 + y2 * y2) * (x1 - x3) +
               (x3 * x3 + y3 * y3) * (x2 - x1);
    double c = 2.0 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    if (fabs(c) < 1e-9) {
        return false;
    }

    pair<double, double> center = {a / c, b / c};
    double radius = hypot(x1 - center.first, y1 - center.second);

    for (const auto& point : points) {
        double distance = hypot(point.first - center.first, point.second - center.second);
        if (fabs(distance - radius) > 1e-9) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Run the same-circumference demonstration.
 * @return int Exit status code returned to the operating system.
 */
int main() {
    vector<pair<double, double>> points = {{1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    cout << boolalpha << on_same_circumference(points) << '\n';
    return 0;
}
