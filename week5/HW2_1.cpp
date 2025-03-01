#include <iostream>
#include <climits> 

using namespace std;

int maximum_sub(int l, int r, int* arr,int depth = 0) {
    if (l == r) { 
        return arr[l];
    }
    
    int mid = (l + r) / 2;
    int left_max = maximum_sub(l, mid, arr);
    int right_max = maximum_sub(mid + 1, r, arr);
    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;
    
    for (int i = mid; i >= l; i--) { 
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }
    
    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }
    return max(max(left_max, right_max), left_sum + right_sum);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maximum_sub(0, n - 1, arr) << endl;

    return 0;
}
