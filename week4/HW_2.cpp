#include <iostream>

using namespace std;    

void quicksort(int,int,int*);
int partition(int,int,int*);

int main(){
    int arr[] = {16,25,2,54,36,9,12,66};
    int n = sizeof(arr)/sizeof(arr[0]);
    quicksort(0,n-1,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void quicksort(int low,int high,int* arr){
    if (low >= high){
        return;
    }
    int partitionIndex = partition(low,high,arr);
    quicksort(low,partitionIndex-1,arr);
    quicksort(partitionIndex+1,high,arr);
}
int partition(int start,int end,int *arr){
    int pivot = arr[start];
    int forward = start;
    int backward = end + 1;
    while(forward < backward){
        do {
            forward++;
        } while (arr[forward] < pivot);
        do {
            backward--;
        } while (arr[backward] > pivot);
        
        swap(arr[forward],arr[backward]);
        
    }
    swap(arr[forward],arr[backward]);   
    swap(arr[start],arr[backward]);
    return backward;
}