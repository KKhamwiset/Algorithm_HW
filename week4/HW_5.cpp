#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int fArray[n];
    int sArray[n];
    for (int i = 0; i < n; i++) {
        cin >> fArray[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> sArray[i];
    }
    int maxBoth = fArray[0];
    for (int i = 1 ; i < n; i++) {
        if (fArray[i] > maxBoth) {
            maxBoth = fArray[i];
        }
    }
    for (int i = 0 ; i < n; i++) {
        if (sArray[i] > maxBoth) {
            maxBoth = sArray[i];
        }
    }
    int freq[maxBoth + 1] = {0};
    int used[maxBoth + 1] = {0};
    for (int i = 0; i < n; i++) {
        if (used[fArray[i]] == 0) {
            freq[fArray[i]]++;
            used[fArray[i]] = -1;
        }
    }
    for (int i = 0; i <= maxBoth; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (used[sArray[i]] == 0) {
            freq[sArray[i]]++;
            used[sArray[i]] = -1;
        }
    }

    // intersection output
    for (int i = 0; i < n; i++) {
        if (freq[fArray[i]] == 2) {
            cout << fArray[i] << " ";
        }
    }
    cout << endl;

    // union output
    for (int i = 0; i < n; i++) {
        if (freq[fArray[i]] > 0) {
            freq[fArray[i]] = 0;
            cout << fArray[i] << " ";
        }
    }
    for (int i = 0; i < n; i++) {
        if (freq[sArray[i]] > 0) {
            freq[sArray[i]] = 0;
            cout << sArray[i] << " ";
        }
    }
    cout << endl;
    return 0;
}