#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> res;

bool solve(vector <int> x,vector <int> cost,int expected){
    for (int i = 1; i <= x.size(); i++){
        if (x[i] == 1){
            expected -= cost[i - 1];
        }
    }
    return expected == 0;
}

void generate_ (vector <int> &x ,vector <int> catalogs,int k,int l,int r){
    if (l == r){
        if (solve(x,catalogs,k)){
            vector<int> temp;
            for (int i = 1; i <= x.size(); i++){
                if (x[i] == 1){
                    temp.push_back(catalogs[i - 1]);
                }
            }
            sort(temp.begin(),temp.end());
            if (temp.size() != 3) return;
            res.push_back(temp);
        }
        return;
    }
    x[l] = 1;
    generate_(x,catalogs,k,l + 1,r);
    x[l] = 0;
    generate_(x,catalogs,k,l + 1,r);
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> catalogs(n,0);
    for (int i = 0; i < n; i++){
        cin >> catalogs[i];
    }
    vector<int> bitmasks(n + 1,0);
    generate_(bitmasks,catalogs,k,1,n);
    if (!res.empty()){
        for (int i = 0; i < 1; i++){
            for (int j = 0; j < res[i].size() && res[i].size() == 3; j++){
                cout << res[i][j] << endl;
            }

        }
    }
    else{
        cout << 0 << endl << 0 << endl << 0 << endl;
    }
    return 0;

}