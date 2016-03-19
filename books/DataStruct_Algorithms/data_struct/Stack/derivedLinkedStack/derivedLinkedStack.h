// linked stack derived from chain
// derives from abstract class stack just to make sure
// all methods of the ADT are implemented

#ifndef derivedLinkedStack_
#define derivedLinkedStack_

#include "chain.h"
#include "stack.h"
#include "myExceptions.h"

using namespace std;

template<class T>
class derivedLinkedStack : private chain<T>,
                           public stack<T>
{
   public:
      derivedLinkedStack(int initialCapacity = 10)
        : chain<T> (initialCapacity) {}
      bool empty() const
           {return chain<T>::empty();}
      int size() const
          {return chain<T>::size();}
      T& top()
         {
            if (chain<T>::empty())
               throw stackEmpty();
             return chain<T>::get(0);
         }
      void pop()
           {
              if (chain<T>::empty())
                 throw stackEmpty();
               chain<T>::erase(0);
           }
      void push(const T& theElement)
    {chain<T>::insert(0, theElement);}
};

#endif
