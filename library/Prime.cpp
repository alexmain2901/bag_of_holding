#include "Prime.h"


namespace Prime
{

bool Util::isPrime(size_t value)
{
  size_t end(value / 2);
  for(size_t i(2); i <= end; ++i)
  {
    if((value % i) == 0x0)
    {
      return false;
    }
  }

  return true;
}

}
