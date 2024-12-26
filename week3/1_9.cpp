#include <iostream>

using namespace std;

int solve(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return n % 2 + solve(n/2);
}

int main(){
    int n;
    cin >> n;
    cout << solve(n) << endl;
}