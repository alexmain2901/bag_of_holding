#ifndef FILTER_H
#define FILTER_H
#include <iostream>
#include <cstdlib>

class Filter
{

public:

  template <class T>
  static int removeDuplicates(T *array, size_t size);

private:
  Filter() = delete;

};


template <class T>
int Filter::removeDuplicates(T *array, size_t size)
{

  //loop through entire array...
  for(int i(0); i < size; ++i)
  {
    //For each index, Check if start index matches any index in the rest 
    //of the array...
    for(int j(i + 1); j < size; ++j)
    {
      //bubble down all members of array if match...
      //update sizes...
      if(array[i] == array[j])
      {
        //recheck the current index as all members have bubbled down...
        --size;
        for(int k(j); k < size; ++k)
        {
          array[k] = array[k + 1];
        }
        --j; 
      }
    }
  }

  return size;
}

#endif

