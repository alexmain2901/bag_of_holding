#ifndef SORT_BUBBLE_SORT_H
#define SORT_BUBBLE_SORT_H
#include <iostream>
#include <cstdlib>

namespace Sort
{

class BubbleSort
{

public:
  template <class T>
  static int sort(T *array, size_t size);
  

private:
  BubbleSort() = delete;

};


template <class T>
int BubbleSort::sort(T *array, size_t size)
{
  int sorted(0);
  while(true)
  {
    for(int i(1); i < size; ++i)
    {
      if(array[i] < array[i - 1])
      {
        sorted = 0;
        T temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
      }
      else
      {
        ++sorted;
      }
    }
    
    if(sorted >= size)
    {
      return 0;
    }
  }
}

}

#endif
