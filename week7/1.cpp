#include <iostream>
#include <algorithm>
using namespace std;

void print(int n, char ar[])
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i];
    }
    cout << "\n";
}

void RightRotate(char arr[], int i, int j)
{
    char temp = arr[j];
    for (int k = j; k > i; k--)
    {
        arr[k] = arr[k - 1];
    }
    arr[i] = temp;
}

void LeftRotate(char arr[], int i, int j)
{
    char temp = arr[i];
    for (int k = i; k < j; k++)
    {
        arr[k] = arr[k + 1];
    }
    arr[j] = temp;
}

void generate(char arr[], int i, int n)
{
    if (i == n - 1)
    {
        print(n, arr);
        return;
    }
    generate(arr, i + 1, n);
    for (int j = i + 1; j < n; j++)
    {
        RightRotate(arr, i, j);
        generate(arr, i + 1, n);
        LeftRotate(arr, i, j);
    }
}

int main() {
    int n;
    cin >> n;
    char arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    generate(arr, 0, n);
    return 0;
}