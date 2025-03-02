#include <iostream>

using namespace std;

int count_ = 0;

bool isPrime(int x){
    if (x < 2) return false;
    for (int i = 2; i < x; i++){
        if (x % i == 0) return false;
    }
    return true;
}


bool checkPrime(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (!isPrime(arr[i] + arr[(i + 1) % n])) {
            return false;
        }
    }
    return true;
}

void generatePermutations(int *arr, int start, int end) {
    if (start == end) {
        if (checkPrime(arr, end + 1)){
            count_++;
        }
        return;
    }
    
    for (int i = start; i <= end; i++) {
        swap(arr[start], arr[i]);
        if (start == 0 || isPrime(arr[start - 1] + arr[start])) {
            generatePermutations(arr, start + 1, end);
        }
        swap(arr[start], arr[i]);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    generatePermutations(arr, 1, n-1);
    cout << count_ << endl;
    return 0;
}