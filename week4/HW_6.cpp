#include <iostream>
#include <cmath>
using namespace std;


void mergeSort(int,int,int*);
void merge(int,int,int,int*);
void digitsDivide(int,int,int&,int*);
int digitsLength(int);

int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i = 0 ; i < n ; i++){
        cin >> array[i];
    }
    mergeSort(0,n - 1,array);
    int totaldigits = 0;
    int indexTracker = 0;
    // first section
    for (int i = 0 ; i < n ; i++){
        totaldigits += digitsLength(array[i]);
        cout << array[i];
    }
    cout << endl;

    int main[totaldigits] = {0};
    for (int i = 0 ; i < n; i++){
        digitsDivide(array[i],digitsLength(array[i]),indexTracker,main);
    }
    //

    int maxDigit = main[0];
    for (int i = 1; i < totaldigits; i++){
        if (main[i] > maxDigit){
            maxDigit = main[i];
        }
    }
    
    int freq[maxDigit + 1] = {0};
    int prev = main[0];
    int streak = 1;
    for (int i = 1; i < totaldigits; i++) {
        if (main[i] == prev) {
            streak++;
        } else {
            if (streak > freq[prev]) {
                freq[prev] = streak;
            }
            prev = main[i];
            streak = 1;
        }
    }

    if (streak > freq[prev]) {
        freq[prev] = streak;
    }
    int maxFreq = -1;
    for (int i = 0 ; i <= maxDigit; i++){
        if (freq[i] > maxFreq){
            maxFreq = freq[i];
        }
    }
    // second section
    for (int j = 0 ; j <= maxDigit; j++){
        if (freq[j] == maxFreq){
            cout << j << " ";
        }
    }
    cout << endl;
    //
    // third section
    prev = -1;
    for (int i = 0; i < totaldigits; i++){
        if (main[i] != prev){
            cout << main[i];
            prev = main[i];
        }
    }
    cout << endl;
    //
    return 0;
}

int digitsLength(int num){
    int count = 1;
    int start = 10;
    while (start <= num){
        count++;
        start = start * 10;
    }
    return count;
}
void digitsDivide(int num,int length,int& index,int *arr){
    if (length == 0){
        return;
    }
    int divisor = (int)(pow(10, length - 1));
    arr[index++] = num / (divisor);
    digitsDivide(num % divisor,length - 1,index,arr);
}
void mergeSort(int start,int end,int *arr){
    if (start >= end){
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(start,mid,arr);
    mergeSort(mid + 1,end,arr);
    merge(start,end,mid,arr);
}
void merge(int left,int right,int mid,int* arr){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int leftArray[leftSize];
    int rightArray[rightSize];
    for (int i = 0; i < leftSize; i++){
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++){
        rightArray[j] = arr[mid + 1 + j];
    }
    int leftPointer = 0,rightPointer = 0;
    int mainPointer = left;
    while (leftPointer < leftSize && rightPointer < rightSize){
        if (leftArray[leftPointer] <= rightArray[rightPointer]){
            arr[mainPointer] = leftArray[leftPointer];
            leftPointer++;
        }
        else{
            arr[mainPointer] = rightArray[rightPointer];
            rightPointer++;
        }
        mainPointer++;
    }
    while (leftPointer < leftSize){
        arr[mainPointer] = leftArray[leftPointer];
        leftPointer++;
        mainPointer++;
    }
    while (rightPointer < rightSize){
        arr[mainPointer] = rightArray[rightPointer];
        rightPointer++;
        mainPointer++;
    }
}