#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Coordinate {
public:
    int x;
    int y;
    Coordinate() {
        x = 0;
        y = 0;
    }
    Coordinate(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

bool compare(Coordinate a, Coordinate b) {
    return a.x < b.x || (a.x == b.x && a.y > b.y);
}

vector<Coordinate> solve(vector<Coordinate>& points, Coordinate target) {
    vector<Coordinate> result;
    int currentEnd = target.x;
    
    while (currentEnd < target.y) {
        int bestEnd = currentEnd;
        int bestIndex = -1;
        
        for (int i = 0; i < points.size(); i++) {
            if (points[i].x <= currentEnd && points[i].y > bestEnd) {
                bestEnd = points[i].y;
                bestIndex = i;
            }
        }
             
        result.push_back(points[bestIndex]);
        currentEnd = bestEnd;
        
        if (currentEnd >= target.y) {
            break;
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<Coordinate> points(n);
    Coordinate target;
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    cin >> target.x >> target.y;
    
    sort(points.begin(), points.end(), compare);
    vector<Coordinate> result = solve(points, target);
    
    cout << result.size() << endl;
    for (Coordinate coord : result) {
        cout << coord.x << " " << coord.y << endl;
    }
    
    return 0;
}