#include <iostream>
#include <cmath>
using namespace std;

int digitLength(int x) {
    int count = 1;
    int temp = x;
    int amp = 10;
    while (temp >= amp) {
        temp /= 10;
        count++;
    }
    return count;
}

int karasuba(int x,int y){
    int a_length = digitLength(x);
    int b_length = digitLength(y);
    if (x <= 10 || y <= 10){
        return x*y;
    }
    int n = max(a_length, b_length);
    int half = n / 2;
    int a1 = x / (int)pow(10,half);
    int a2 = x % (int)pow(10,half);
    int b1 = y / (int)pow(10,half);
    int b2 = y % (int)pow(10,half);
    int ac = karasuba(a1,b1);
    int bd = karasuba(a2,b2);
    int C = karasuba(a1 + a2,b1 + b2) - ac - bd;
    cout << ac << " " << bd << " " << C << endl;
    return ac * (int)pow(10,half * 2) + C * (int)pow(10,half) +(bd);

}

int main(){
    int x,y;
    cin >> x >> y;
    cout << karasuba(x,y);
}
