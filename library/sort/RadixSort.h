#ifndef SORT_RADIX_SORT_H
#define SORT_RADIX_SORT_H
#include <iostream>
#include <cstdlib>
#include <string.h>


namespace Sort
{

class RadixSort
{

public:
  template <class T>
  static int sort(T *array, size_t size, size_t base);

private:
  RadixSort() = delete;

};


template <class T>
int RadixSort::sort(T *array, size_t size, size_t base)
{

  //Allocate buckets to store values in...
  T **bucket = new (std::nothrow) T*[base];
  for(size_t i(0); i < base; ++i)
  {
    bucket[i] = new (std::nothrow) T[size];
  }

  //allocate bucket indexes...
  size_t *bucket_index = new (std::nothrow) size_t[base];

  //loop over each values index... (i.e. 100 has 3 & 1 has 1...)
  size_t end;
  size_t offset(1);
  do 
  {
    end = 0;
    memset(bucket_index, 0, base * sizeof(size_t));
    //put array values into there respective buckets...
    for(size_t i(0); i < size; ++i)
    {
      size_t index = (array[i] / offset) % base;
      end |= (array[i] / offset);
      bucket[ index ][ bucket_index[ index ]++ ] = array[i];
    }

    //store the current order...
    T *ptr = &array[0];
    for(size_t i(0); i < base; ++i)
    {
      for(size_t j(0); j < bucket_index[i]; ++j)
      {
        *ptr = bucket[i][j];
         ++ptr;
      }
    }

    offset *= base;
  } while( end != 0 );

  //Clean up allocation...
  for(size_t i(0); i < base; ++i)
  {
    delete[] bucket[i];
  }

  delete[] bucket_index;
}

}

#endif
