#ifndef SORT_SELECTION_SORT_H
#define SORT_SELECTION_SORT_H
#include <iostream>
#include <cstdlib>

namespace Sort
{

class SelectionSort
{

public:
  template <class T>
  static int sort(T *array, size_t size);
  

private:
  SelectionSort() = delete;

};


template <class T>
int SelectionSort::sort(T *array, size_t size)
{

  for(size_t i(0); i < size; ++i)
  {
    T min(array[i]);
    size_t index(i + 1);
    bool swap(false);
    for(size_t j(i + 1); j < size; ++j)
    {
      if(array[j] < min)
      {
        swap = true;
        index = j;
        min = array[j];
      }
    }

    if(swap)
    {
      T temp = array[i];
      array[i] = array[index];
      array[index] = temp;
    }
  }
}

}

#endif
