#include <iostream>
#include <cstdlib>

/**
* @brief Fizz Buzz, every number divisable by 3 prints fizz, by 5 prints buzz.
*        This program counts up to the supplied number and prints out the results
*        to standard output.
*/
int main(int argc, char **argv)
{
  if(argc < 2)
  {
    std::cout << "Error: Not enough arguments. [HINT] Supply max count" << std::endl;
  }

  size_t count(0);
  size_t end = atoi(argv[1]);
  for(int i(1); i < end; ++i)
  {
    bool fizz(false);
    if(i % 3 == 0)
    {
      std::cout << "fizz";
      fizz = true;
    }
    
    bool buzz(false);
    if(i % 5 == 0)
    {
      std::cout << "buzz";
      buzz = true;
    }
    
    if(fizz && buzz)
    {
      ++count;
    }
    else if(!(fizz || buzz))
    {
      std::cout << i;
    }

    std::cout << " ";
  }

  std::cout << std::endl;
  std::cout << "Total fizzbuzz: " << count << std::endl;
  return 0;
}
