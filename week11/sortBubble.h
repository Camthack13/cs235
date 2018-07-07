/***********************************************************************
 * Module:
 *    Week 11, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort
 ****************************************************/
template <class T>
void sortBubble(T array[], int num)
{

   int i;
   int j;
   for (i = 0; i < num-1; i++)
   {      
      for (j = 0; j < num-i-1; j++)
      { 
         if (array[j] > array[j+1])
         {
             T temp = array[j];
             array[j] = array[j+1];
             array[j+1] = temp;
         }
      }
   }
}


#endif // SORT_BUBBLE_H
