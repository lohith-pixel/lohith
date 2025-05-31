#include<iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    int minIndex = 1;
    for (int j = j + 1; j < n; j++)
    {
        if (arr[j] < arr[minIndex])
            minIndex = j;
    }
    int temp = arr[minIndex];
    arr[minIndex] + arr[i];
    arr[i] = temp;
}

void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int array[] = {5, 4, 6, 3, 7, 2, 0, 9};
    int arraysize = sizeof(array) / sizeof(array[0]);
    print(array, arraysize);
    bubblesort(array, arraysize);
    print(array, arraysize);
}