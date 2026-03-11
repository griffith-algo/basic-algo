#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Point {
    double x;
    double y;
    /**
     * @brief Run the operator< step used in this example.
     * @param other const Point& The other value used by this function.
     * @return bool True when the required condition is satisfied, otherwise false.
     */
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

/**
 * @brief Return the straight-line distance between two points.
 * @param left const Point& The left-side data or left boundary used by the algorithm.
 * @param right const Point& The right-side data or right boundary used by the algorithm.
 * @return double The numeric result produced by the algorithm.
 */
double euclidean_distance(const Point& left, const Point& right) {
    double dx = left.x - right.x;
    double dy = left.y - right.y;
    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Check every pair of points and return the closest pair.
 * @param points const vector<Point>& The points used by the geometry algorithm.
 * @return pair<pair<Point, Point>, double> The pair of values produced by the algorithm.
 */
pair<pair<Point, Point>, double> brute_force_closest_pair(const vector<Point>& points) {
    double best_distance = numeric_limits<double>::infinity();
    pair<Point, Point> best_pair{};
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double distance = euclidean_distance(points[i], points[j]);
            if (distance < best_distance) {
                best_distance = distance;
                best_pair = {points[i], points[j]};
            }
        }
    }
    return {best_pair, best_distance};
}

/**
 * @brief Return the closest pair of points using divide and conquer.
 * @param points_sorted_x const vector<Point>& The points_sorted_x value used by this function.
 * @param points_sorted_y const vector<Point>& The points_sorted_y value used by this function.
 * @return pair<pair<Point, Point>, double> The pair of values produced by the algorithm.
 */
pair<pair<Point, Point>, double> closest_pair(const vector<Point>& points_sorted_x,
                                              const vector<Point>& points_sorted_y) {
    if (points_sorted_x.size() <= 3) {
        return brute_force_closest_pair(points_sorted_x);
    }

    size_t mid = points_sorted_x.size() / 2;
    Point mid_point = points_sorted_x[mid];

    vector<Point> left_x(points_sorted_x.begin(), points_sorted_x.begin() + static_cast<long>(mid));
    vector<Point> right_x(points_sorted_x.begin() + static_cast<long>(mid), points_sorted_x.end());
    vector<Point> left_y;
    vector<Point> right_y;
    for (const Point& point : points_sorted_y) {
        if (point.x < mid_point.x || (point.x == mid_point.x && left_y.size() < left_x.size())) {
            left_y.push_back(point);
        } else {
            right_y.push_back(point);
        }
    }

    auto left_result = closest_pair(left_x, left_y);
    auto right_result = closest_pair(right_x, right_y);
    auto best_result = left_result.second < right_result.second ? left_result : right_result;

    vector<Point> strip;
    for (const Point& point : points_sorted_y) {
        if (abs(point.x - mid_point.x) < best_result.second) strip.push_back(point);
    }

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < best_result.second; ++j) {
            double distance = euclidean_distance(strip[i], strip[j]);
            if (distance < best_result.second) {
                best_result = {{strip[i], strip[j]}, distance};
            }
        }
    }
    return best_result;
}

/**
 * @brief Return which side of a line a point lies on.
 * @param p1 const Point& The first point that defines the reference line or distance check.
 * @param p2 const Point& The second point that defines the reference line or distance check.
 * @param p const Point& A single point used by the geometry algorithm.
 * @return int The integer result produced by the algorithm.
 */
int findSide(const Point& p1, const Point& p2, const Point& p) {
    double value = (p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x);
    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}

/**
 * @brief Return a value proportional to the distance from a point to a line.
 * @param p1 const Point& The first point that defines the reference line or distance check.
 * @param p2 const Point& The second point that defines the reference line or distance check.
 * @param p const Point& A single point used by the geometry algorithm.
 * @return double The numeric result produced by the algorithm.
 */
double lineDist(const Point& p1, const Point& p2, const Point& p) {
    return abs((p.y - p1.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p.x - p1.x));
}

/**
 * @brief Recursively collect the boundary points of the convex hull.
 * @param points const vector<Point>& The points used by the geometry algorithm.
 * @param p1 const Point& The first point that defines the reference line or distance check.
 * @param p2 const Point& The second point that defines the reference line or distance check.
 * @param side int The side value used by this function.
 * @param hull set<Point>& The hull value used by this function.
 * @return void This function updates data or prints results and does not return a value.
 */
void quickHull(const vector<Point>& points, const Point& p1, const Point& p2, int side, set<Point>& hull) {
    int farthest_index = -1;
    double max_distance = 0.0;
    for (int index = 0; index < static_cast<int>(points.size()); ++index) {
        double distance = lineDist(p1, p2, points[index]);
        if (findSide(p1, p2, points[index]) == side && distance > max_distance) {
            farthest_index = index;
            max_distance = distance;
        }
    }

    if (farthest_index == -1) {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    Point farthest_point = points[farthest_index];
    quickHull(points, farthest_point, p1, -findSide(farthest_point, p1, p2), hull);
    quickHull(points, farthest_point, p2, -findSide(farthest_point, p2, p1), hull);
}

/**
 * @brief Return the convex hull of the given points using QuickHull.
 * @param points const vector<Point>& The points used by the geometry algorithm.
 * @return vector<Point> The vector produced by the algorithm.
 */
vector<Point> getHull(const vector<Point>& points) {
    int min_x = 0;
    int max_x = 0;
    for (int i = 1; i < static_cast<int>(points.size()); ++i) {
        if (points[i].x < points[min_x].x) min_x = i;
        if (points[i].x > points[max_x].x) max_x = i;
    }
    set<Point> hull;
    quickHull(points, points[min_x], points[max_x], 1, hull);
    quickHull(points, points[min_x], points[max_x], -1, hull);
    return vector<Point>(hull.begin(), hull.end());
}

struct HuffmanNode {
    int frequency;
    char symbol;
    shared_ptr<HuffmanNode> left;
    shared_ptr<HuffmanNode> right;
    /**
     * @brief Run the is leaf step used in this example.
     * @return bool True when the required condition is satisfied, otherwise false.
     */
    bool is_leaf() const { return left == nullptr && right == nullptr; }
};

/**
 * @brief Build a Huffman tree from the symbol frequencies.
 * @param alphabet const vector<char>& The list of symbols used to build the Huffman tree.
 * @param frequencies const unordered_map<char, int>& The symbol frequencies used to build the Huffman tree.
 * @return shared_ptr<HuffmanNode> The pointer to the constructed node or data structure.
 */
shared_ptr<HuffmanNode> build_huffman_tree(const vector<char>& alphabet,
                                           const unordered_map<char, int>& frequencies) {
    auto compare = [](const shared_ptr<HuffmanNode>& left, const shared_ptr<HuffmanNode>& right) {
        return left->frequency > right->frequency;
    };
    priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, decltype(compare)> queue(compare);
    for (char symbol : alphabet) {
        queue.push(make_shared<HuffmanNode>(HuffmanNode{frequencies.at(symbol), symbol, nullptr, nullptr}));
    }
    while (queue.size() > 1) {
        auto left = queue.top();
        queue.pop();
        auto right = queue.top();
        queue.pop();
        queue.push(make_shared<HuffmanNode>(HuffmanNode{left->frequency + right->frequency, '\0', left, right}));
    }
    return queue.top();
}

/**
 * @brief Traverse the Huffman tree to assign codewords to symbols.
 * @param node const shared_ptr<HuffmanNode>& The node currently processed by the function.
 * @param codeword const string& The codeword value used by this function.
 * @param codewords unordered_map<char, string>& The mapping from each symbol to its Huffman codeword.
 * @return void This function updates data or prints results and does not return a value.
 */
void dfs_traversal(const shared_ptr<HuffmanNode>& node, const string& codeword,
                   unordered_map<char, string>& codewords) {
    if (node->is_leaf()) {
        codewords[node->symbol] = codeword.empty() ? "0" : codeword;
        return;
    }
    dfs_traversal(node->left, codeword + "0", codewords);
    dfs_traversal(node->right, codeword + "1", codewords);
}

/**
 * @brief Return the Huffman codeword for each symbol.
 * @param root const shared_ptr<HuffmanNode>& The root node of the current tree.
 * @return unordered_map<char, string> The value produced by this function.
 */
unordered_map<char, string> get_codewords(const shared_ptr<HuffmanNode>& root) {
    unordered_map<char, string> codewords;
    dfs_traversal(root, "", codewords);
    return codewords;
}

/**
 * @brief Encode a string using the supplied Huffman codewords.
 * @param input const string& The input value used by this function.
 * @param codewords const unordered_map<char, string>& The mapping from each symbol to its Huffman codeword.
 * @return string The string produced by the algorithm.
 */
string huffman_encode(const string& input, const unordered_map<char, string>& codewords) {
    string encoded;
    for (char symbol : input) encoded += codewords.at(symbol);
    return encoded;
}

/**
 * @brief Decode a Huffman bit string back into text.
 * @param encoded const string& The encoded value used by this function.
 * @param root const shared_ptr<HuffmanNode>& The root node of the current tree.
 * @return string The string produced by the algorithm.
 */
string huffman_decode(const string& encoded, const shared_ptr<HuffmanNode>& root) {
    string decoded;
    auto current = root;
    for (char bit : encoded) {
        current = bit == '0' ? current->left : current->right;
        if (current->is_leaf()) {
            decoded.push_back(current->symbol);
            current = root;
        }
    }
    return decoded;
}

/**
 * @brief Run the small demonstration for this teaching example.
 * @return int The integer result produced by the algorithm.
 */
int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}, {30, 25}};
    vector<Point> points_sorted_x = points;
    vector<Point> points_sorted_y = points;
    sort(points_sorted_x.begin(), points_sorted_x.end(), [](const Point& left, const Point& right) {
        return left.x < right.x || (left.x == right.x && left.y < right.y);
    });
    sort(points_sorted_y.begin(), points_sorted_y.end(), [](const Point& left, const Point& right) {
        return left.y < right.y;
    });
    auto closest = closest_pair(points_sorted_x, points_sorted_y);
    cout << "Closest pair distance: " << closest.second << '\n';
    cout << "Closest pair: (" << closest.first.first.x << ", " << closest.first.first.y << ") and ("
         << closest.first.second.x << ", " << closest.first.second.y << ")\n\n";

    vector<Point> hull_points = {{1, 3}, {3, 3}, {3, 5}, {4, 5}, {5, 2}, {6, 3}, {6, 6}, {8, 4}, {9, 1}, {10, 2}};
    auto hull = getHull(hull_points);
    cout << "QuickHull points: ";
    for (const auto& point : hull) cout << '(' << point.x << ", " << point.y << ") ";
    cout << "\n\n";

    vector<char> alphabet = {'A', 'B', 'C', 'D', 'E'};
    unordered_map<char, int> frequencies = {{'A', 1}, {'B', 1}, {'C', 1}, {'D', 1}, {'E', 12}};
    string input = "ABCDEABCDEABCDEE";
    auto root = build_huffman_tree(alphabet, frequencies);
    auto codewords = get_codewords(root);
    string encoded = huffman_encode(input, codewords);
    cout << "Encoded string: " << encoded << '\n';
    cout << "Decoded string: " << huffman_decode(encoded, root) << '\n';
    return 0;
}
