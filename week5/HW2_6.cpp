#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int pen_and_pencil(int x, int y) {
    if (x < 10 ) {
        return x * y;
    }

    int a_length = to_string(x).size();
    int b_length = to_string(y).size();

    int half = a_length / 2;

    int power = pow(10, half);
    int a1 = x / power;
    int a2 = x % power;
    int b1 = y / power;
    int b2 = y % power;

    int D = pen_and_pencil(a2, b2);
    int B = pen_and_pencil(a2, b1);
    int C = pen_and_pencil(a1, b2);
    int A = pen_and_pencil(a1, b1);
    cout << A << " " << B << " " << C << " " << D << endl;
    return A * pow(10, 2 * half) + ((B + C) * power) + D;
}

int main() {
    int x, y;
    cin >> x >> y;
    int result = pen_and_pencil(x, y);
    cout << result;
    return 0;
}