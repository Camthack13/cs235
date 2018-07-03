
#ifndef map_H
#define map_H
#include <iostream>
#include <cassert>  // because I am paranoid
#include <string>
#include "bst.h"    // for Stack
#include "pair.h"

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG
namespace custom{
    
/************************************************
 * map
 * A class that holds stuff
 ***********************************************/
template <class T1, class T2>
class map
{
private:
    BST<pair<T1, T2> > data;
    
public:
    
    //Constructor
    map() {
        
    }
    //Copy Constuctor
   map(const map<T1,T2> & rhs)
   {
      data = rhs.data;
   }
   //Assignment
   map & operator = (const map & rhs) throw (const char *)
   {
      data = rhs.data;
      return * this;
   }
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
    //insert()
    void insert(T1 key, T2 value)  throw(const char *)
    {
       pair<T1,T2> pair(key,value);
       data.insert(pair);
         
    }
      //insert()
    void insert(pair<T1,T2> pair)  throw(const char *)
    {
         data.insert(pair);
    }
    //[] operator
    T2 & operator [] (T1 index)       throw (const char *)
    {
            pair<T1,T2> pair(index,T2());
            
            
            if(data.find(pair) == NULL)
            {
               data.insert(pair);
            }
            
            return (data.find(pair)).getNode()->data.second;
            
    }
 //   const T2 & operator [] (T1 index) const throw (const char *)
 //   {
 //            pair<T1,T2> pair(index,T2());
            
            
            
 //           return 
 //   }
        
    class iterator;
    
    //find()
    iterator find(T1 t)
    {
    
         pair<T1,T2> pPPair(t,T2());
         
        BSTIterator< pair<T1,T2> > bstit;
        bstit = data.find(pPPair);
         iterator it(bstit);
         return it;
        
         
         
    
    }
    
    //begin()
    iterator begin() 
    {
    BSTIterator< pair<T1,T2> > bstit;
    bstit = data.begin();
    iterator it(bstit);
    return it;
       
    }
    
    //end()
    iterator end() 
    {
    BSTIterator< pair<T1,T2> > bstit;
    bstit = data.end();
    iterator it(bstit);
    return it;
       
    }
    
    
    
    
};
template <class T1, class T2>
class map<T1,T2> :: iterator
{
private:

public:
   BSTIterator< pair<T1,T2> > it;

   iterator() {}

   iterator(BSTIterator<pair<T1,T2> > & itU)
   {
       it = itU;
   }
   iterator (const iterator& itU)
   {
        it = itU.it;
   }
//assigment
   iterator & operator = (const iterator & rhs)
   {
      it = rhs.it;
   }
//isequal
   bool operator == (const iterator & rhs) const
   {
      return(it == rhs.it);
   }
//isNotEwial
   bool operator != (const iterator & rhs) const
   {
      return(it != rhs.it);
   }
//incremtn
   iterator & operator ++ ()
   {
      it++;
      return *this;
   }
//decremtnt
   iterator & operator -- ()
   {
      it--;
      return *this;
   } 
//defrencerence
   pair<T1,T2> & operator * ()
   {
      return *it;
   }
   
};


};//ending namespace custom
#endif // map_H





