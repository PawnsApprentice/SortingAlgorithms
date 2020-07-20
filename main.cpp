/**
* Title: Algorithm Efficiency and Sorting
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 1
* Description: This is the main method
*/




#include "Sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
This function generates a random array
*/
void  randArrayGenerator(int* arr, int arrsize)
{

    for(int i = 0; i < arrsize; i++)
    {
         arr[i] = rand();
    }

}

/**
This function copies an array to another array sent via the parameter.
This was done so all algorithms have the same dataset
*/
void copyArray(int* arrayToCopy, int* arrayToSave, int n)
{

    for (int i = 0; i < n; i++)
    {
        arrayToSave[i] = arrayToCopy[i];
    }

}

int main()
{

//    //clocks for the sorting algorithms
//    clock_t tinsertion;
//    clock_t tselection;
//    clock_t tbubblesort;
//    clock_t tmergesort;
//    clock_t tquicksort;
//
//    unsigned long long  movecountsel,  compcountsel;
//    unsigned long long  movecountins, compcountins;
//    unsigned long long  movecountbubble,  compcountbubble;
//    unsigned long long  movecountmerge, compcountmerge;
//    unsigned long long movecountquick, compcountquick;
//
    unsigned long long tempy, tempy1;
//
//
//    //size of arrays
//
//    int sizeArr =  20000;
//    int sizeArr1 = 22000;
//    int sizeArr2 = 24000;
//    int sizeArr3 = 26000;
//    int sizeArr4 = 28000;
//
//    //arrays of different sizes i.e 20,000 etc (By default the arrays of size 20,000 are selected)
//    /**
//    Note:- The array names do not represent the size i.e checkeighyins meaning "check eighty insertion" does not mean its size is eighty. This was done before
//    the homework was modified to include only range of values between 20-30000. It does mean however, it is intended for the insertionSort function. Toggle one at
//    a time since there may be memory issues
//    */
//     int checktwentyins [sizeArr]; int checktwentysel [sizeArr]; int checktwentybubble [sizeArr]; int checktwentymerge [sizeArr]; int checktwentyquick [sizeArr];
//    //int checkfortyins [sizeArr1], checkfortysel [sizeArr1] , checkfortybubble[sizeArr1], checkfortymerge[sizeArr1], checkfortyquick[sizeArr1];
//    // int checksixtyins [sizeArr2], checksixtysel[sizeArr2], checksixtybubble[sizeArr2], checksixtymerge[sizeArr2], checksixtyquick[sizeArr2];
//    // int checkeightyins[sizeArr3], checkeightysel[sizeArr3], checkeightybubble[sizeArr3], checkeightymerge[sizeArr3], checkeightyquick[sizeArr3];
//    //int checkhundredins[sizeArr4]; int checkhundredsel[sizeArr4]; int checkhundredbubble[sizeArr4]; int checkhundredmerge[sizeArr4]; int checkhundredquick[sizeArr4];
//
//    // arrays randomized
///**
//arrays are randomized here, by default the array of size 20,000 for the insertionSort function has been chosen
//*/
//     randArrayGenerator(checktwentyins, sizeArr);
//    //   randArrayGenerator(checkfortyins, sizeArr1);
//    //randArrayGenerator(checksixtyins, sizeArr2);
//    // randArrayGenerator(checkeightyins, sizeArr3);
//    //randArrayGenerator(checkhundredins, sizeArr4);
//
//
///**
//this is commented out, only for when descending sorted datasets are needed
//*/
//   //Sorting::descendingSort(checkhundredins, sizeArr4);
//
///**
//this is commented out, only for when ascending sorted datasets are needed
//*/
////    Sorting::quickSort(checktwentyins, sizeArr,temp, temp1);
//
//
///**
//arrays copied so every algorithm has the same array data set, by default arrays for the 20,000 range are
//selected so all functions can be called instantly with the same dataset
//*/
//
//   // copied for twenties
//   copyArray(checktwentyins,checktwentysel,sizeArr); copyArray(checktwentyins,checktwentybubble,sizeArr); copyArray(checktwentyins,checktwentymerge,sizeArr); copyArray(checktwentyins,checktwentyquick,sizeArr);
//
////    //copied for forties
////  copyArray(checkfortyins,checkfortysel,sizeArr1); copyArray(checkfortyins,checkfortybubble,sizeArr1); copyArray(checkfortyins,checkfortymerge,sizeArr1); copyArray(checkfortyins,checkfortyquick,sizeArr1);
////
////    //copied for sixties
// //   copyArray(checksixtyins,checksixtysel,sizeArr2); copyArray(checksixtyins,checksixtybubble,sizeArr2); copyArray(checksixtyins,checksixtymerge,sizeArr2); copyArray(checksixtyins,checksixtyquick,sizeArr2);
////
////    //copied for eighties
////      copyArray(checkeightyins,checkeightysel,sizeArr3); copyArray(checkeightyins,checkeightybubble,sizeArr3); copyArray(checkeightyins,checkeightymerge,sizeArr3); copyArray(checkeightyins,checkeightyquick,sizeArr3);
////
////    //copied for hundreds
// //   copyArray(checkhundredins,checkhundredsel,sizeArr4); copyArray(checkhundredins,checkhundredbubble,sizeArr4); copyArray(checkhundredins,checkhundredmerge,sizeArr4); copyArray(checkhundredins,checkhundredquick,sizeArr4);
//
//
//
//
///**
//Only function parameters need to be changed e.g checkhundred , sizeArr4 for a dataset of 28,000 values
//By default, it is set for a dataset of 20,000 values as noted by checktwentyins and sizeArr
//*/
//
////    for insertion sort
//    tinsertion = clock();
//    Sorting::insertionSort(checktwentyins, sizeArr, compcountins, movecountins);
//    tinsertion = clock() - tinsertion;
//    printf ("It took me %d clicks (%f seconds).\n",tinsertion,((float)tinsertion)/CLOCKS_PER_SEC);
//    cout<< "comparisons done: " << compcountins << " and the movings done: " << movecountins << endl;
//
//
//    cout<< "_____________________________________________________________________________________________________"<< endl;
//
//
//
////       for selection sort
//    tselection = clock();
//    Sorting::selectionSort(checktwentysel ,sizeArr, compcountsel, movecountsel);
//    tselection = clock() - tselection;
//    printf ("It took me %d clicks (%f seconds).\n",tselection,((float)tselection)/CLOCKS_PER_SEC);
//    cout<< "comparisons done: " << compcountsel << " and the movings done: " << movecountsel << endl;
//
//
//    cout<< "_____________________________________________________________________________________________________"<< endl;
//
//        //for bubble sort
//    tbubblesort = clock();
//    Sorting::bubbleSort(checktwentybubble ,sizeArr, compcountbubble, movecountbubble);
//    tbubblesort = clock() - tbubblesort;
//    printf ("It took me %d clicks (%f seconds).\n",tbubblesort,((float)tbubblesort)/CLOCKS_PER_SEC);
//    cout<< "comparisons done: " << compcountbubble << " and the movings done: " << movecountbubble<< endl;
//
//
//    cout<< "_____________________________________________________________________________________________________"<< endl;
//
//
//          //for merge sort
//    tmergesort = clock();
//    Sorting::mergeSort(checktwentymerge ,sizeArr, compcountmerge, movecountmerge);
//    tmergesort = clock() - tmergesort;
//    printf ("It took me %d clicks (%f seconds).\n",tmergesort,((float)tmergesort)/CLOCKS_PER_SEC);
//    cout<< "comparisons done: " << compcountmerge << " and the movings done: " << movecountmerge<< endl;
//
//
//    cout<< "_____________________________________________________________________________________________________"<< endl;
//
//   // for quick sort
//    tquicksort = clock();
//    Sorting::quickSort(checktwentyquick ,sizeArr, compcountquick, movecountquick);
//    tquicksort = clock() - tquicksort;
//    printf ("It took me %d clicks (%f seconds).\n",tquicksort,((float)tquicksort)/CLOCKS_PER_SEC);
//    cout<< "comparisons done: " << compcountquick << " and the movings done: " << movecountquick << endl;
//    cout<< "_____________________________________________________________________________________________________"<< endl;
//

int temp [8] = {4,8,3,7,6,2,1,5};

Sorting::quickSort(temp, 8, tempy, tempy1 );


    return 0;
}
