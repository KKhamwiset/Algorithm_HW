#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> a, int target, vector<vector<int>>&result){
    for (int i = 0; i < a.size(); i++){
        for (int j = i + 1; j < a.size(); j++){
            if (a[i] + a[j] == target){
                vector<int> temp;
                temp.push_back(a[i]);
                temp.push_back(a[j]);
                result.push_back(temp);
            }
        }
    }
}
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> v;
    vector<vector<int>> result;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    solve(v,x,result);
    if (!result.empty()){
        for (int i = 0; i < result.size(); i++){
            for (int j = 0; j < result[i].size(); j++){
                cout << result[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else{
        cout << -1 << '\n';
    }
}