/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
/*
SelectionSort(array,n)
  FOR iPivot <- n-1 … 1
  {
     iLargest <- 0
     FOR iCheck <- 1 … iPivot-1
     {
        IF (array [iLargest] = array[iCheck])
           iLargest? iCheck
     }
     IF (array[iLargest] > array[iPivot])
     {
        swap array[iLargest],array[iPivot]
     }
   }
*/

   int iPivot, iCheck, mindex;
 
    // One by one move boundary of unsorted subarray
    for (iPivot = 0; iPivot < num-1; iPivot++)
    {
        // Find the minimum element in unsorted array
        mindex = iPivot;
        for (iCheck = iPivot+1; iCheck < num; iCheck++)
          if (array[iCheck] < array[mindex])
            mindex = iCheck;
 
        // Swap the found minimum element with the first element
         T temp = array[mindex];
         array[mindex] = array[iPivot];
         array[iPivot] = temp;
    }

}


#endif // SORT_SELECTION_H
