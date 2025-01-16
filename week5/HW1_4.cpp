#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void KN(vector<int>& A, int M, int k) {
    sort(A.begin(), A.end());
    int i = 0;
    int range = k;
    while (i < A.size() && A[i] < M - range) {
        i++;
        range/=2;
    }
    int left = i - 1, right = i;

    while (right - left <= k) {
        cout << left << " " << right << endl;
        if (abs(A[left] - M) >  abs(A[right] - M)) {
            right++;
        } else {
            left--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int M, k;
    cin >> M >> k;
    KN(A, M, k);
    return 0;
}
