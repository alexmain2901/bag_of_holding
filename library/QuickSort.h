#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H
#include <iostream>
#include <cstdlib>

namespace Sort
{

class QuickSort
{

public:
  template <class T>
  static int sort(T *array, size_t size);
  

private:
  QuickSort() = delete;

  template <class T>
  static int sort(T *array, size_t start, size_t end);
};


template <class T>
int QuickSort::sort(T *array, size_t size)
{
  return sort(array, 0, size - 1);
}


template <class T>
int QuickSort::sort(T *array, size_t start, size_t end)
{

  if(start >= end)
  {
    return 0;
  }

  size_t pivot(end);
  size_t _start(start);
  while(_start < pivot)
  {
    if(array[_start] > array[pivot])
    {
      T temp = array[_start];
      array[_start] = array[pivot - 1];
      array[pivot - 1] = array[pivot];
      array[pivot] = temp;
      --pivot;
    }
    else
    {
      ++_start;
    }
  }

  sort(array, start, _start - 1);
  sort(array, _start + 1, end);
  return 0; 
}

}

#endif
