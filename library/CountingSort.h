#ifndef SORT_COUNTING_SORT_H
#define SORT_COUNTING_SORT_H
#include <iostream>
#include <cstdlib>
#include <string.h>
#include "Print.h"

namespace Sort
{

class CountingSort
{

public:
  template <class T>
  static int sort(T *array, size_t size);
  
  template <class T>
  static int max_value(T *array, size_t size, T &value);

private:
  CountingSort() = delete;

};


template <class T>
int CountingSort::sort(T *array, size_t size)
{
  T max;
  if(max_value(array, size, max) == 0)
  {
    //Allocate for largest member...
    ++max;
    T *bucket = new (std::nothrow) T[max];
    if(bucket == nullptr)
    {
      return -1;
    }

    //Build histogram...
    memset(bucket, 0, max * sizeof(*bucket));
    for(size_t i(0); i < size; ++i)
    {
      ++bucket[array[i]];
    }

    T *ptr = &array[0];
    //place back into original array...
    for(size_t i(0); i < max; ++i)
    {
      for(size_t j(bucket[i]); j > 0; --j)
      {
        *ptr = i;
        ++ptr;
      }
    }

    return 0;
  }

  return -1;
}

template <class T>
int CountingSort::max_value(T* array, size_t size, T &value)
{
  //Check for bounds...
  if((size < 1) || (array == nullptr))
  {
    return -1;
  }

  //search for max...
  value = array[0];
  for(size_t i(1); i < size; ++i)
  {
    if(value < array[i])
    {
      value = array[i];
    }
  }

  return 0;
}

}

#endif
