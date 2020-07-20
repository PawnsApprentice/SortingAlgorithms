/**
* Title: Algorithm Efficiency and Sorting
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 1
* Description: This is the Sorting class containing all the sorting algorithms functions
*/




#include <iostream>
using namespace std;
#include "Sorting.h"


/**
This method swaps the two values that inputs to the method
*/
void Sorting::swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;

}

/**
This method is used by the Selectionsort function and finds the index of the largest value in the array
*/
int Sorting::indexOfLargest(const int theArray[], int size, unsigned long long& compCount, unsigned long long& moveCount) //for selectionSort
{
    int indexSoFar = 0;
    for (int currentIndex=1; currentIndex<size;++currentIndex)
    {
        compCount++;
        if (theArray[currentIndex] > theArray[indexSoFar])
            indexSoFar = currentIndex;
    }
    return indexSoFar;

}

/**
This method is the selectionSort function that implements the selectionSort algorithm
*/
void Sorting::selectionSort( int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount)
{
    for (int last = n-1; last >= 1; --last) {
    int largest = indexOfLargest(theArray, last+1, compCount, moveCount);
    moveCount = moveCount + 3;
    swap(theArray[largest], theArray[last]);
    }
}

/**
This method is the a function that sorts an array in descending order, a reverse of insertionSort function basically
*/
 void Sorting::descendingSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}

/**
This function implements the Insertion Sort algorithm
*/
void Sorting::insertionSort(int arr[], int n, unsigned long long& compCount, unsigned long long& moveCount)
{

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            compCount++;
            moveCount++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        moveCount++;
        arr[j + 1] = key;
    }
}

/**
This function implements the Bubble Sort algorithm
*/
void Sorting::bubbleSort(int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount)
{
    bool sorted = false;

	for (int pass = 1; (pass < n) && !sorted; ++pass) {
      sorted = true;
      for (int index = 0; index < n-pass; ++index) {
         int nextIndex = index + 1;
         compCount++;
         if (theArray[index] > theArray[nextIndex]) {
            moveCount = moveCount + 3;
            swap(theArray[index], theArray[nextIndex]);
            sorted = false; // signal exchange
         }
      }
   }
}

/**
This function uses the mergeSort function and is a modified version of the mergeSort algorithm with fewer parameters
*/
void Sorting::mergeSort(int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount)
{

    mergeSort(theArray, 0, (n-1), compCount, moveCount);

}

/**
This function implements the mergeSort algorithm
*/
void Sorting::mergeSort(int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount)
{

    compCount++;
    if (first < last) {

        int mid = (first + last)/2; 	// index of midpoint

        mergeSort(theArray, first, mid, compCount, moveCount);

        mergeSort(theArray, mid+1, last, compCount, moveCount);

        // merge the two halves
        merge(theArray, first, mid, last, compCount, moveCount );
   }
}

/**
This function is a helper function for the mergeSort function
*/

void Sorting::merge( int arr[], int l, int m, int r, unsigned long long& compCount, unsigned long long& moveCount) //for mergeSort
{
     int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
            compCount++;
        if (L[i] <= R[j]) {

            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        compCount++;
        moveCount++;
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
            compCount++;
            moveCount++;
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
            compCount++;
            moveCount++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
This function uses the quickSort function and is a modified version of the quickSort algorithm with fewer parameters
*/
void Sorting::quickSort(int theArray[], int n, unsigned long long& compCount, unsigned long long& moveCount)
{
    quickSort(theArray, 0, (n-1), compCount, moveCount);
}


/**
This function implements the quickSort algorithm
*/
void Sorting::quickSort(int theArray[], int first, int last, unsigned long long& compCount, unsigned long long& moveCount)
{
        cout << "_________________________________"<<endl;
        cout<< "quicksort called with the following parameters: "<< first << "  "<< last << endl;
        cout << "_________________________________"<<endl;
        for(int i = 0; i < 8; i++)
        {
            cout<< "dealing with array: " << theArray[i]<< endl;
        }
        cout << "_________________________________"<<endl;

    int pivotIndex;

   if (first < last) {

      // create the partition: S1, pivot, S2
      partition(theArray, first, last, pivotIndex, compCount, moveCount);

      // sort regions S1 and S2
      quickSort(theArray, first, pivotIndex-1, compCount, moveCount);
      quickSort(theArray, pivotIndex+1, last, compCount, moveCount);
   }

}

/**
This function is a helper function for the quickSort algorithm
*/
void Sorting::partition(int theArray[], int first, int last,int& pivotIndex, unsigned long long& compCount, unsigned long long& moveCount)
{

        cout << "_________________________________"<<endl;
        cout<< "partition called with the following parameters: "<< first << "  "<< last << endl;
        cout << "_________________________________"<<endl;

        for(int i = 0; i < 8; i++)
        {
            cout<< "dealing with array: " << theArray[i]<< endl;
        }
        cout << "_________________________________"<<endl;

    // Precondition: theArray[first..last] is an array; first <= last.
   // Postcondition: Partitions theArray[first..last] such that:
   //   S1 = theArray[first..pivotIndex-1] < pivot
   //   theArray[pivotIndex] == pivot
   //   S2 = theArray[pivotIndex+1..last] >= pivot

	// place pivot in theArray[first]
   //choosePivot(theArray, first, last);

   int pivot = theArray[first]; // copy pivot

    int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {

      compCount++;
      if (theArray[firstUnknown] < pivot) {  	// belongs to S1
		  ++lastS1;
		  moveCount = moveCount + 3;
    	  swap(theArray[firstUnknown], theArray[lastS1]);
      }	// else belongs to S2
   }
   // place pivot in proper position and mark its location
   moveCount = moveCount +3;
   swap(theArray[first], theArray[lastS1]);
   pivotIndex = lastS1;

   cout<< " by the way the pivot index is: " << pivotIndex << endl;
}








