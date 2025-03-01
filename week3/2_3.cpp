#include <iostream>
#include <vector>

using namespace std;

void shellsort(vector<int> &arr, int n);
void printArray(const vector<int> &arr);

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    shellsort(arr, n);
    return 0;
}

void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}   

void shellsort(vector<int> &arr, int n) {
    vector<int> gaps = {1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int gapIndex = gaps.size() - 1;
    while (gapIndex >= 0 && gaps[gapIndex] >= n) {
        gapIndex--;
    }
    for (int gap = gaps[gapIndex]; gapIndex >= 0; gap = gaps[--gapIndex]) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }   
            arr[j] = temp;
        }
        printArray(arr);
    }
}
