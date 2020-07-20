
/**
* Title: Algorithm Efficiency and Sorting
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 1
* Description: This is header file for Sorting class
*/



#ifndef __SORTING_H
#define __SORTING_H

#include <string>
using namespace std;
#include <iostream>

class Sorting{

public:


static void swap(int &x, int &y);
static int indexOfLargest(const int theArray[], int size, unsigned long long& compCount, unsigned long long& moveCount); //for selectionSort
static void selectionSort( int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount);

static void insertionSort(int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount);
static void descendingSort(int theArray[], int n);
static void bubbleSort(int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount);
static void mergeSort(int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount);
static void mergeSort( int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount);
static void merge( int arr[], int l, int m, int r, unsigned long long& compCount, unsigned long long& moveCount); //for mergeSort
static void quickSort(int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount);
static void quickSort(int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount);
static void partition(int theArray[], int first, int last, int &pivotIndex, unsigned long long& compCount, unsigned long long& moveCount);


};

#endif
