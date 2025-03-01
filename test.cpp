#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line {
    int x_i, x_j;
};

// Sorting function: First by `x_i`, then by `x_j` in descending order
bool compare(Line a, Line b) {
    if (a.x_i == b.x_i)
        return a.x_j > b.x_j;
    return a.x_i < b.x_i;
}

int minSegmentsToCover(int xa, int xb, vector<Line>& segments) {
    sort(segments.begin(), segments.end(), compare);

    int current_end = xa, max_extend = xa, count = 0;
    int i = 0, n = segments.size();
    while (current_end < xb) {
        bool found = false;
        // Find the best segment to extend coverage
        while (i < n && segments[i].x_i <= current_end) {
            max_extend = max(max_extend, segments[i].x_j);
            i++;
            found = true;
        }

        if (!found) return -1; // Cannot extend coverage

        count++;
        current_end = max_extend;

        if (current_end >= xb) break;
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    vector<Line> segments(n);

    for (int i = 0; i < n; i++)
        cin >> segments[i].x_i >> segments[i].x_j;

    int xa, xb;
    cin >> xa >> xb;

    int result = minSegmentsToCover(xa, xb, segments);
    cout << result << endl;

    return 0;
}
