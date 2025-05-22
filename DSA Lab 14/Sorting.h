#pragma once
#ifndef SORTING_H
#define SORTING_H

struct SortStats 
{
    long long comparisons = 0;
    long long exchanges = 0;
};

void bubbleSort(int arr[], int n, SortStats& stats);
void selectionSort(int arr[], int n, SortStats& stats);
void insertionSort(int arr[], int n, SortStats& stats);
void heapSort(int arr[], int n, SortStats& stats);
void generateFixedInput(int* arr, int n);
void copyArray(int* src, int* dest, int n);

#endif