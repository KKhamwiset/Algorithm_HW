#include <iostream>
#include <climits>
using namespace std;


int* distribution_couting(int*,int,int,int);

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int u,l;
    u = INT_MIN;
    l = INT_MAX;
    for (int i = 0 ; i < n;i++){
        if (arr[i] > u){
            u = arr[i];
        }
        if (arr[i] < l){
            l = arr[i];
        }
    }
    
    int* result = distribution_couting(arr,n,l,u);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

int* distribution_couting(int* arr,int n,int l,int u){
    int* D = new int[(u - l) + 1];
    int* S = new int[n];
    for (int i = 0 ; i < (u - l) + 1;i++){ D[i] = 0;}
    for (int i = 0 ; i < n;i++){
        D[arr[i] - l]++;
    }
    for (int j = 1 ; j < (u - l) + 1 ;j++){
        D[j] = D[j] + D[j - 1];
    }
    for (int i = n - 1 ; i >= 0 ;i--){
        int j = arr[i] - l;
        S[D[j] - 1] = arr[i];
        D[j]--;
    }
    return S;
}
