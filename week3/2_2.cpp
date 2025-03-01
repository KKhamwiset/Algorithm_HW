#include <iostream>

using namespace std;
void mergeSort(int *,int,int);
void merge(int ,int ,int,int *);
int solve(int *arr,int left,int right,int target,int min){
    if (left > right){
        return min; 
    }
    if (arr[left] + arr[right] == target){
        if (min > arr[right] -  arr[left]) {
            min = abs(arr[right] - arr[left]);   
            solve(arr, left + 1, right - 1, target, min);
        }
    }
    else if (arr[left] + arr[right] > target){
        solve(arr, left, right - 1, target, min);
    }
    else{
        solve(arr, left + 1, right, target, min);
    }
}

int main(){
    int n,target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    // int result = solve(arr,0,n-1,target,INT8_MAX);
    // cout << result << endl;
    for (auto i : arr){
        cout << i << " ";
    }
}   
void mergeSort(int *arr,int start ,int end){
    if (start >= end){
        return;    
    }
    int mid = (start + end) / 2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(start,end,mid,arr);
}
void merge(int left,int right,int mid,int* main){
    cout << "========================================" << endl;
    cout << "Left: " << left << " Right: " << right << " Mid: " << mid << endl;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;            
    int leftArray[leftSize];
    int rightArray[rightSize];
    cout << "Left Array: " << endl;
    for (int i = 0; i < leftSize; i++){
        leftArray[i] = main[left + i];  
    }
    for (auto i : leftArray){
        cout << i << " ";
    }
    cout << endl;
    for (int j = 0; j < rightSize; j++ ){
        rightArray[j] = main[mid + 1 + j];
    }
    cout << "Right Array: " << endl;
    for (auto i : rightArray){
        cout << i << " ";
    }
    cout << endl;
    int leftPointer = 0,rightPointer = 0;
    int mainPointer = left ;
    cout << "Main Pointer at index : " << mainPointer << endl;
    while (leftPointer < leftSize && rightPointer < rightSize){
            cout << "Comparing: " << leftArray[leftPointer] << " and " << rightArray[rightPointer] << endl;
            if (leftArray[leftPointer] <= rightArray[rightPointer]){
                cout << leftArray[leftPointer] << " is less than " << rightArray[rightPointer] << endl;
                main[mainPointer] = leftArray[leftPointer];
                leftPointer++;
            }
            else{
                cout << rightArray[rightPointer] << " is less than " << leftArray[leftPointer] << endl;
                main[mainPointer] = rightArray[rightPointer];
                rightPointer++; 
            }
            mainPointer++;
    }
    while (leftPointer < leftSize){
        main[mainPointer] = leftArray[leftPointer];
        leftPointer++;  
        mainPointer++;      
    }
    while (rightPointer < rightSize){
        main[mainPointer] = rightArray[rightPointer];
        rightPointer++;         
        mainPointer++;      
    }   
     cout << "========================================" << endl;
}