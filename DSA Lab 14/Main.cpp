#include <iostream>
#include <iomanip>
#include "sorting.h"
using namespace std;

void runSorts(int* original, int n) 
{
    int* data = new int[n];
    SortStats bStats, sStats, iStats, hStats;
    copyArray(original, data, n);
    bubbleSort(data, n, bStats);
    copyArray(original, data, n);
    selectionSort(data, n, sStats);
    copyArray(original, data, n);
    insertionSort(data, n, iStats);
    copyArray(original, data, n);
    heapSort(data, n, hStats);
    cout << setw(6) << n << "\t";
    cout << setw(10) << bStats.comparisons << "\t" << setw(10) << bStats.exchanges << "\t";
    cout << setw(10) << sStats.comparisons << "\t" << setw(10) << sStats.exchanges << "\t";
    cout << setw(10) << iStats.comparisons << "\t" << setw(10) << iStats.exchanges << "\t";
    cout << setw(10) << hStats.comparisons << "\t" << setw(10) << hStats.exchanges << endl;
    delete[] data;
}

int main() 
{
    const int testSizes[] = { 10, 100, 1000, 5000, 10000, 20000, 50000 };
    cout << "   N\tBubbleComp\tBubbleExch\tSelectComp\tSelectExch\tInsertComp\tInsertExch\tHeapComp\tHeapExch\n";
    for (int size : testSizes) 
    {
        int* input = new int[size];
        generateFixedInput(input, size);
        runSorts(input, size);
        delete[] input;
    }
    return 0;
}