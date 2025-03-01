#include <iostream>

using namespace std;

void print_sol(int x[], int k) {
    for (int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void genreate_(int x[], int l, int n, int k,int &count) {
    if (l > k) {
        print_sol(x, k);
        count++;
        return;
    } 
    int j;
    if (l == 0){
        j = 1;
    }
    else{
        j = x[l - 1] + 1;
    }
    for (int i = j; i <= n; i++) {
        x[l] = i;
        genreate_(x, l + 1, n, k,count);
    }
} 

int main(){
    int n,k,count = 0;
    cin >> n >> k;
    int x[k + 1] = {0};
    genreate_(x, 1, n, k,count);
    cout << count << endl;
    return 0;


}