#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> maximum_con_subsequence(const vector<int>& A) {
    vector<int> subseq;
    int max_seq = A.size();
    double max_sum = -INT8_MAX;
    while (max_seq > 0) {
        for (int i = 0; i < max_seq; i++) {
            vector<int> temp;
            double current_sum = 0;

            for (int j = i; j < max_seq; j++) {
                temp.push_back(A[j]);
                current_sum += A[j];
            }

            if (current_sum > max_sum) {
                max_sum = current_sum;
                subseq = temp;
            }
        }
        max_seq--;
    }

    if (!subseq.empty()) {
        return subseq;
    }
    else {
        subseq.push_back(0);
        return subseq;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    vector<int> result = maximum_con_subsequence(A);
    int c = 0;
    for (int i : result) {
        c += i;
    }
    cout << c << '\n';
    return 0;
}
