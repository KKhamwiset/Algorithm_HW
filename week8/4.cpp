#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int solve(vector<int> v, vector<int>& older, vector<int>& younger){
    older.push_back(v[0]);
    younger.push_back(v[1]);
    int olderSum = v[0];
    int youngerSum = v[1];
    for(int i = 2; i < v.size(); i++){
        if(olderSum < youngerSum){
            older.push_back(v[i]);
            olderSum += v[i];
        }
        else{
            younger.push_back(v[i]);
            youngerSum += v[i];
        }   
    }
    return abs(olderSum - youngerSum);
}
void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n * 2);
    vector<int> older;
    vector<int> younger;
    for(int i = 0; i < n * 2; i++){
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    cout << solve(v, older, younger) << endl;
    // print(older);
    // print(younger);
    return 0;
}