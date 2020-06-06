#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <iostream>
#include <cstdlib>
#include "Heap.h"

template <class T>
class MaxHeap : public Heap<T>
{

public:
  MaxHeap(T *array, size_t size); 
  virtual void sort();
  virtual void insert(T value);
  virtual void remove(T value);
  virtual void print(std::string sep=" "){ return Heap<T>::print(sep); }
};

template <class T>
MaxHeap<T>::MaxHeap(T *array, size_t size)
{
  for(size_t i(0); i < size; ++i)
  {
    this->insert(array[i]);
  }
}

template <class T>
void MaxHeap<T>::sort()
{
  size_t end(this->size() - 1);
  while(end > 0)
  {
    T temp = this->m_heap[0];
    this->m_heap[0] = this->m_heap[end];
    this->m_heap[end] = temp;

    //move root down...
    --end;
    size_t root(0);
    for(int k(0); k < 10; ++k)
    {
      size_t lC = this->child_left(root);
      if(lC > end)
      {
        break;
      }

      size_t rC = lC + 1;
      size_t swap = root;
      if(this->m_heap[swap] < this->m_heap[lC])
      {
        swap = lC;
      }
      
      if(rC <= end)
      {
        if(this->m_heap[lC] < this->m_heap[rC])
        {
          swap = rC;
        }
      }

      if(swap == root)
      {
        break;
      }
      else
      {
        temp = this->m_heap[root];
        this->m_heap[root] = this->m_heap[swap];
        this->m_heap[swap] = temp;
        root = swap;
      }
    }
  }
}

template <class T>
void MaxHeap<T>::insert(T value)
{
  this->push_back(value);

  size_t index(this->size() - 1);
  while(index > 0)
  {
    T parentValue;
    (void)this->get(this->parent(index), parentValue);
    if(parentValue < value)
    {
      (void)this->set(this->parent(index), value);
      (void)this->set(index, parentValue);
      index = this->parent(index);
    }
    else
    {
      return;
    }
  }
}

template <class T>
void MaxHeap<T>::remove(T value)
{
  
}


#endif
