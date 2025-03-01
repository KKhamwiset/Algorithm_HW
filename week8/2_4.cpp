#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string checksum(vector<int>& A, vector<int>& B, int K) {
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    for(int i = 0; i < A.size(); i++) {
        if(A[i] + B[i] < K) {
            return "No";
        }
    }
    return "Yes";
}

int main() {
    int m;
    cin >> m;
    
    while(m--) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> B[i];
        }
        int K;
        cin >> K;
        
        cout << checksum(A, B, K) << endl;
    }
    return 0;
}