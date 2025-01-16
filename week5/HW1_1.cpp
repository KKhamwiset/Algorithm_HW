#include <iostream>


using namespace std;


void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int l, int r, int* arr, int n) {
    cout << "\nPartitioning array from :" << l << " to " << r << endl;
    int mid = l + (r - l) / 2;

    if (arr[l] > arr[mid]) {
        swap(arr[l], arr[mid]);
    }
    if (arr[l] > arr[r]) {
        swap(arr[l], arr[r]);
    }
    if (arr[mid] > arr[r]) {
        swap(arr[mid], arr[r]);
    }

    int pivot = arr[mid];
    swap(arr[mid], arr[r]); 
    int s = l - 1; 
    int e = r;     

    while (true) {
        do {
            s++;
        } while (arr[s] < pivot);

        do {
            e--;
        } while (arr[e] > pivot);

        if (s >= e) { 
            break;
        }

        swap(arr[s], arr[e]);
        printArray(arr, n);
    }

    swap(arr[s], arr[r]);
    printArray(arr, n);
    cout << "s: " << s << endl;
    return s;
}

int quickselect(int arr[], int left, int right, int k, int n) {
    if (left == right) {
        return arr[left];
    }
    int p = partition(left, right, arr, n);
    // cout << "p: " << p << " k: " << k << " left : "<< left << endl;
    if ((k - 1) == (p - left)) {
        // cout << k - 1 << p;
        return arr[p];
    } else if ((k - 1) < (p - left)) {
        return quickselect(arr, left, p - 1, k, n);
    } else {
        k = (k - p - left) - 1;
        return quickselect(arr, p + 1, right, k, n);
    }
}

int main() {
    int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = n;
    printArray(arr, n);
    cout  << quickselect(arr, 0, n - 1, k, n) << endl;
    return 0;
}
