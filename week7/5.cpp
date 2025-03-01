#include <iostream>
#include <climits>
using namespace std;

int max_ = INT_MIN;

void print_sol(int *x, int k) {
    for (int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void gen(int *seq,int *arr, int l, int r,int sum = 0) {
    if (l > r) {
        // print_sol(seq, r);
        max_ = max(max_,sum);
        return;
    }
    seq[l] = 0;
    gen(seq, arr, l + 1, r,sum);
    if (l == 0){
        seq[l] = 1; 
        gen(seq,arr, l + 1, r,sum + arr[l-1]);

    }
    else{
        if (seq[l - 1] == 1){
            return;
        }
        seq[l] = 1; 
        gen(seq, arr,l + 1, r,sum + arr[l-1]);
    }
}

int main() {
    int n;
    cin >> n;
    int val[n];
    for (int i = 0 ; i < n;i++){
        cin >> val[i];
    }
    int binary[n + 1] = {0}; 
    gen(binary,val, 1, n); 
    cout  << max_ << endl;
}
