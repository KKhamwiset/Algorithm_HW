#include <iostream>
#include <vector>
using namespace std;

int interpolation(vector<int>, vector<int>&, int, int, int);

int main() {
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> v(n);
    vector<int> pointers;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int low = 0;
    int high = v.size() - 1;
    int result = interpolation(v, pointers, target, low, high);
    if (result != -1) {
        for (int i : pointers) {
            cout << i << " ";
        }
        cout << '\n';
    } else {
        cout << "Not Found" << endl;
    }
}

int interpolation(vector<int> v, vector<int>& pointers, int target, int low, int high) {
    if (low > high || v[low] > target || v[high] < target) {
        return -1;  
    }
    int searchPointer = low + ((target - v[low]) * (high - low)) / (v[high] - v[low]);
    if (searchPointer < low || searchPointer > high){
        return -1;
    }
    
    pointers.push_back(searchPointer);

    if (v[searchPointer] == target) {
        return searchPointer;

    } else if (v[searchPointer] < target) {
        return interpolation(v, pointers, target, searchPointer + 1, high);
        
    } else {
        return interpolation(v, pointers, target, low, searchPointer - 1);
    }
}
