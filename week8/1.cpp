#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


double totalValue = 0;

class Item {
    public:
        int index;
        double weight;
        double value;
        double ratio;
};

bool compareRatio(Item a, Item b) {
    return a.ratio > b.ratio; 
}

vector<double> solve(int n, double W, vector<double>& weights, vector<double>& values) {
    vector<Item> items(n);
    vector<double> result(n, 0.0); 
    for(int i = 0; i < n; i++) {
        items[i] = {i, weights[i], values[i], values[i]/weights[i]};
    }
    
    sort(items.begin(), items.end(), compareRatio);
    
    double currentWeight = 0;
    
    for(int i = 0; i < n; i++) {
        if(currentWeight + items[i].weight <= W) {
            result[items[i].index] = 1.0;
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            double remain = W - currentWeight;
            result[items[i].index] = remain/items[i].weight;
            totalValue += items[i].value * (remain/items[i].weight);
            break;
        }
    }
    
    cout << fixed;
    cout.precision(2);
    return result;
}
int main(){
    int n;
    double W;
    cin >> n >> W;
    vector<double> weights(n);
    vector<double> values(n);
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    vector<double> result = solve(n, W, weights, values);
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    cout << totalValue << endl;
    return 0;
}