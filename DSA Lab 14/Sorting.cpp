#include "sorting.h"
using namespace std;

void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void copyArray(int* src, int* dest, int n)
{
    for (int i = 0; i < n; ++i)
    {
        dest[i] = src[i];
    }
}

void bubbleSort(int arr[], int n, SortStats& stats)
{
    bool switched;
    for (int pass = 0; pass < n - 1; pass++)
    {
        switched = false;
        for (int j = 0; j < n - pass - 1; j++)
        {
            stats.comparisons++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                stats.exchanges++;
                switched = true;
            }
        }
        if (!switched)
        {
            break;
        }
    }
}

void selectionSort(int arr[], int n, SortStats& stats)
{
    for (int a = 0; a < n; a++) 
    {
        int key = a;
        for (int b = a + 1; b < n; b++)
        {
            stats.comparisons++;
            if (arr[b] < arr[key])
                key = b;
        }
        if (key != a) 
        {
            swap(arr[a], arr[key]);
            stats.exchanges++;
        }
    }
}

void insertionSort(int arr[], int n, SortStats& stats)
{
    for (int k = 1; k < n; k++) 
    {
        int y = arr[k];
        int j = k - 1;
        while (j >= 0 && y < arr[j]) 
        {
            stats.comparisons++;
            arr[j + 1] = arr[j];
            j--;
            stats.exchanges++;
        }
        stats.comparisons++;
        arr[j + 1] = y;
    }
}

void heapify(int arr[], int n, int i, SortStats& stats) 
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n) 
    {
        stats.comparisons++;
        if (arr[l] > arr[largest])
            largest = l;
    }

    if (r < n) 
    {
        stats.comparisons++;
        if (arr[r] > arr[largest])
            largest = r;
    }

    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        stats.exchanges++;
        heapify(arr, n, largest, stats);
    }
}

void heapSort(int arr[], int n, SortStats& stats) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, stats);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        stats.exchanges++;
        heapify(arr, i, 0, stats);
    }
}

void generateFixedInput(int* arr, int n) 
{
    for (int i = 0; i < n; ++i)
        arr[i] = (i * 37 + 23) % 10007;
}