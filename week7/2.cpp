#include <iostream>

using namespace std;

void print_sol(int x[], int k) {
    for (int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void generate_(int x[], bool used[], int l, int n, int k,int &count) {
    if (l > k) {
        print_sol(x, k);
        count++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            x[l] = i;
            used[i] = true;
            generate_(x, used, l + 1, n, k,count);
            used[i] = false;   
        }
    }
}

int main() {
    int n, k,count = 0;
    cin >> n >> k;
    int x[k + 1];      
    bool used[n + 1] = {false}; 
    generate_(x, used, 1, n, k,count);
    cout << count << endl;
    return 0;
}
