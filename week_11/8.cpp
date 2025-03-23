#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

double findMean(const vector<int>& arr) {
    double sum = accumulate(arr.begin(), arr.end(), 0.0);
    
    if (arr.size() == 0) {
        return 0.0;
    }
    
    return sum / arr.size();
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    double mean = findMean(arr);
    cout << fixed << setprecision(2) << mean << endl;
    
    return 0;
}