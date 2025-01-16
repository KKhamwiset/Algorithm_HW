#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void KN(vector<int> &A, int M, int k,int l,int r)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int left = 0, right = n - 1, mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (A[mid] < M)
            left = mid + 1;
        else
            right = mid;
    }
    left = right - 1;
    right = right;
    while (k--){
        cout << left << " " << right << endl;
        if (left < 0){
            right++;
        }
        else if (right > n){
            left--;
        }
        else if (abs(A[left] - M) <= abs(A[right] - M)){
            left--;
        }
        else{
            right++;
        }
    }

}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int M, k;
    cin >> M >> k;
    KN(A, M, k,0,A.size() - 1);
    return 0;
}
