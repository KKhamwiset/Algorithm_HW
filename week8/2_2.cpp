#include <iostream>
using namespace std;

int squares(int m, int n) {
    int count = 0;
    while (m > 0 && n > 0) {
        if (m > n) {
            count += m/n;
            m = m % n;
        } else {
            count += n/m;
            n = n % m;
        }
    }
    
    return count;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << squares(m, n) << endl;
    return 0;
}