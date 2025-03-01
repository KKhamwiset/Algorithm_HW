#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Time{
    public:
        double arrivalTime;
        double departTime;
        Time(){
            this->arrivalTime = 0;
            this->departTime = 0;
        }
        Time(double arrivalTime, double departTime){
            this->arrivalTime = arrivalTime;
            this->departTime = departTime;
        }
};

bool compare(Time a, Time b){
    return  a.departTime < b.departTime;
}
int solve (vector<Time> a){
    vector<Time> b;
    int count = 0;
    b.push_back(a[0]);
    for (int i = 1; i < a.size(); i++){
        for (int j = count; j >= 0; j--){
            if (a[i].arrivalTime <= b[j].departTime){
                count++;
                break;
            }
        }
    }
    return count;
}
    
int main() {
    int n;
    cin >> n;
    vector<Time> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].arrivalTime >> a[i].departTime;
    }
    sort(a.begin(), a.end(), compare);
    int count;
    count = solve(a);
    cout << count << endl;
    return 0;
}