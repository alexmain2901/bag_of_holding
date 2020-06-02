#ifndef SORT_MERGE_SORT_H
#define SORT_MERGE_SORT_H
#include <iostream>
#include <cstdlib>

namespace Sort
{

class MergeSort
{

public:
  template <class T>
  static int sort(T *array, size_t size);
  

private:
  MergeSort() = delete;

  template <class T>
  static int _sort(T *array, size_t size);
};


template <class T>
int MergeSort::sort(T *array, size_t size)
{
  size_t middle(size / 2);
  if(middle > 1)
  {
    _sort(array, size);
  }
  else if(middle == 1)
  {
    if(array[1] < array[0])
    {
      T temp(array[0]);
      array[0] = array[1];
      array[1] = temp;
    }
  }

  return 0; 
}

template <class T>
static int _sort(T *array, size_t size)
{
  size_t middle(size/2);
  for(size_t index(2); index < middle; index = index * 2)
  {
    for(size_t i(0); i < size; i = i + index)
    {
      
    }
  }
}

#endif
