/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
int binarySearch(T a[], T item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;
 
    int mid = (low + high)/2;
 
    if(item == a[mid])
        return mid+1;
 
    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
 


template <class T>
void sortInsertion(T array[], int num)
{
    int i;
    int target;
    int j;
    int k;
    T selected;
 
    for (i = 1; i < num; ++i)
    {
        j = i - 1;
        selected = array[i];
 
        // find location where selected sould be inseretd
        target = binarySearch(array, selected, 0, j);
 
        // Move all elements after location to create space
        while (j >= target)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = selected;
    }
}



#endif // SORT_INSERTION_H
