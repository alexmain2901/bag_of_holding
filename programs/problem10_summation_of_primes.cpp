
#include <iostream>
#include "../library/Prime.h"

/**
* @brief Summation of primes program...
*  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*  Find the sum of all the primes below two million.
*/
int main(int argc, char **argv)
{
  if(argc < 2)
  {
    std::cout << "Incorrect argument count, [HINT] supply size" << std::endl;
  }  

  size_t summation(0); 
  size_t max = atoi(argv[1]);

  //Include the provided member in the check, use less than for faster checks...
  for(int i(2); i < max; ++i)
  {
    if(Prime::Util::isPrime(i))
    {
      summation += i;
      std::cout << "                              \r";
      std::cout << "Progress: " << ((i / (double)max) * 100.0);
      std::cout.flush();
    }
  }

  std::cout << "                              \r";
  std::cout << "Prime summation is: " << summation << std::endl;

  return 0;
}
