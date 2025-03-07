#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

double solve(vector<double> v){
    double totalLength = v[0];
    for(int i = 1; i < v.size(); i++){
        v[i] += v[i - 1];
        totalLength += v[i];
    }
    return totalLength / v.size();
}

int main(){
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    cout << fixed << setprecision(2);
    cout << solve(v) << endl;
    return 0;
}