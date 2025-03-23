#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> numlist;
int solve (vector<int> &A , int n , int k , vector<vector<int>> &memo){
    if (k < 0 || n == A.size()){
        return -2 ;
    }
    if (k == 0){
        return 0;
    }
    if (memo[n][k] != -1){
        return memo[n][k] ;
    }
    memo[n][k] = max(solve (A , n + 1 , k , memo) , solve (A , n + 1 , k - A[n] , memo)+1);
    return memo[n][k];
}   

int main(){
    int n ,k;
    cin >> n ;
    vector<int> A(n) ;
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> A[i] ;
    }
    cin >> k ;
    vector<vector<int>> memo(n, vector<int>(k + 1, -1));
    int ans =  solve (A , 0 , k , memo);
    if (ans == -2){
        cout << 0 << endl;
    }
    else {
        cout << ans << endl;
    }
    
    return 0;
}