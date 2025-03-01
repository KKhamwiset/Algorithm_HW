int quickselect(int arr[], int left, int right, int k, int n,int &count) {
    if (left == right) {
        return arr[left];
    }
    count++;
    int p = partition(left, right, arr, n);
    // cout << "p: " << p << " k: " << k << " left : "<< left << endl;
    if ((k - 1) == (p - left)) {
        // cout << k - 1 << p;
        return arr[p];
    } else if ((k - 1) < (p - left)) {
        return quickselect(arr, left, p - 1, k, n,count);
    } else {
        k = k - (p - left) - 1;
        return quickselect(arr, p + 1, right, k, n,count);
    }
}