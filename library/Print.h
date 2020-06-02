#ifndef PRINT_H
#define PRINT_H
#include <iostream>

class Print 
{

public:
  template <class T>
  static void array(T *array, size_t size, std::string sep=" ");

private:
  Print() = delete;

};

template <class T>
void Print::array(T *array, size_t size, std::string sep)
{
  for(int i(0); i < size; ++i)
  {
    std::cout << array[i] << sep;
  }

  std::cout << std::endl;
}

#endif
