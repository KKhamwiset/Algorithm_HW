#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> v,vector<int>& left,vector<int>& right){
    left.push_back(v[0]);
    right.push_back(v[1]);
    int leftSum = v[0];
    int rightSum = v[1];
    for(int i = 2; i < v.size(); i++){
        if(leftSum < rightSum){
            left.push_back(v[i]);
            leftSum += v[i];
        }
        else{
            right.push_back(v[i]);
            rightSum += v[i];
        }
    }
    return abs(leftSum - rightSum);
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> left;
    vector<int> right;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    cout << solve(v, left, right) << endl;
    return 0;
}