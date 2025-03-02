#include <iostream>
using namespace std;

int squares(int w, int h) {
    int count = 0;
    while (w > 0 && h > 0) {
        if (w > h) {
            count += w/h;
            w = w % h;
        } else {
            count += h/w;
            h = h % w;
        }
    }
    
    return count;
}

int main() {
    int w, h;
    cin >> w >> h;
    cout << squares(w,h) << endl;
    return 0;
}