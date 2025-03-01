#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int MAX_TIME = 100000;
    vector<int> timeline(MAX_TIME + 1, 0);

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        timeline[start]++;    
        timeline[end + 1]--;   
    }

    int max_customer = 0, current_customer = 0;
    int max_start = -1, max_end = -1, temp_start = -1;
    for (int t = 0; t <= MAX_TIME; t++) {
        current_customer += timeline[t];
        if (current_customer > max_customer) {
            max_customer = current_customer;
            max_start = t;
            temp_start = t;
        }

        if (current_customer < max_customer && temp_start != -1) {
            max_end = t - 1; 
            temp_start = -1;
        }
    }

    cout << max_start << " " << max_end << " " << max_customer << endl;

    return 0;
}
