#include <iostream>
#include <climits> 

using namespace std;

int maximum_sub(int l, int r, int* arr,int depth = 0) {
    for (int i = 0; i < depth; i++) cout << "  ";
    cout << "Processing range [" << l << ", " << r << "]" << endl;

    if (l == r) {
        for (int i = 0; i < depth; i++) cout << "  ";
        cout << "Base case: arr[" << l << "] = " << arr[l] << endl;
        return arr[l];
    }
    if (l == r) { 
        return arr[0];
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
     for (int i = 0; i < depth; i++) cout << "  ";
    cout << "Results for range [" << l << ", " << r << "]: "
         << "left_max = " << left_max
         << ", right_max = " << right_max
         << ", cross_max = " << (left_sum + right_sum) << endl;

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
