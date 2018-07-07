/***********************************************************************
 * Module:
 *    Week 11, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"
#include <cassert>
using namespace custom;
/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   BST<T> btree;
   T temp;
   for(int i = 0; i < num; i++)
   {
      temp = array[i];
      btree.insert(temp);
   }
   BSTIterator<T> it = btree.begin();
    for(int i = 0; i < num; i++)
   {
      array[i] = *it;
       if(it != btree.end())
       it++;
   }
   
}


#endif // SORT_BINARY_H
