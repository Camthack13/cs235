
#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <cassert>  // because I am paranoid
#include <string>
#include "pair.h"
#include "bst.h"
// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG
namespace custom{

template <class T1, class T2>
class map
{
   private:
   BST< pair <T1 , T2> > data;

   public:
   //Constructers
   map() {}
   //Copy Constructer
   map(const map<T1,T2> & rhs)
   {
      data(rhs.data);
   }
   //Assignment
   map & operator = (const map & rhs) throw (const char *)
   {
      data = rhs.data;
   }
   class iterator;
   //size
   int size()
   {
      return data.size();
   }
   //Empty
   bool empty()
   {
      return data.empty();
   }
   //Clear
   void clear()
   {
      data.clear();
   }
   //access

   //find


   //insert


   //begin

   //end


};




 };//ending namespace custom   
#endif // BST_H




