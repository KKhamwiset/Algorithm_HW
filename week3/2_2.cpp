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
    int result = solve(arr,0,n-1,target,INT8_MAX);
    cout << result << endl;
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
void merge(int left,int right,int mid,int * main){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;            
    int leftArray[leftSize];
    int rightArray[rightSize];

    for (int i = 0; i < leftSize; i++){
        leftArray[i] = main[left + i];  
    }
    for (int j = 0; j < rightSize; j++ ){
        rightArray[j] = main[mid + 1 + j];
    }
    int leftPointer = 0,rightPointer = 0;
    int mainPointer = left ;
    while (leftPointer < leftSize && rightPointer < rightSize){
            if (leftArray[leftPointer] <= rightArray[rightPointer]){
                main[mainPointer] = leftArray[leftPointer];
                leftPointer++;
            }
            else{
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

}