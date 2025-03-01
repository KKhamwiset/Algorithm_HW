#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Chocolate{
    public:
        int value;
        int baseInx;
        Chocolate(){value = 0;baseInx = 0;}
        Chocolate(int value,int baseInx){
            this->value = value;
            this->baseInx = baseInx;
        }
};
bool compare(Chocolate a, Chocolate b){
    return a.value > b.value;
}

int solve(vector<Chocolate> a){
    int sum = a[0].value;
    vector<int> usedInx;
    usedInx.push_back(a[0].baseInx);
    for (int i = 1; i < a.size(); i++){
        bool conflict = false;
        for (int j = 0; j < usedInx.size(); j++){
            if (a[i].baseInx == usedInx[j] - 1 || a[i].baseInx == usedInx[j] || a[i].baseInx == usedInx[j] + 1){
                conflict = true;
                break;
            }
        }
        if (!conflict){
            sum += a[i].value;
            usedInx.push_back(a[i].baseInx);
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<Chocolate> a;
    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        a.push_back(Chocolate(val,i));
    }
    sort(a.begin(), a.end(), compare);
    cout << solve(a);
    return 0;
}