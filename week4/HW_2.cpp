#include <iostream>

using namespace std;    

void quicksort(int,int,int*);
int partition(int,int,int*);

int main(){
    int arr[] = {2,3,1,5,4};
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
    int back = end - 1;
    while(true){
        do{
            forward++;
        } while (arr[forward] < pivot && forward < end);
        do{
            back--;
        } while(arr[back] > pivot && back > start);

        if (forward >= back){
            break;
        }
        cout << "Swapping " << arr[forward] << " and " << arr[back] << endl;
        swap(arr[forward],arr[back]);
    }
    cout << "Swapping " << arr[forward] << " and " << arr[start]<< endl;
    swap(arr[forward],arr[start]);
    return forward;
}