#include <iostream>
#include <cstdlib>

/**
* @brief Find the first triangle value with 500 divisors...
*/

size_t divisors(size_t value)
{
  size_t count(0);
  for(size_t i(1); i <= value; ++i)
  {
    if(i % value == 0)
    {
      ++count;
    }
  }

  return count;
}

int main(int argc, char **argv)
{
  if(argc < 2)
  {
    std::cout << "Error: not enough parameters. [HINT] provide divisors count" << std::endl;
    return -1;
  }
  size_t count(0);
  size_t end(atoi(argv[1]));
  size_t i(1);
  size_t value(0);
  while(count < end)
  {
    std::cout << i << ": ";

    size_t divCount(divisors(i));
    std::cout << divCount << std::endl;
    count = divCount;
    value = i;
    i += (i + 1);
  }


  std::cout << "Value: " << value << std::endl;
  return 0;
}
