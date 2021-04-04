# cpp-utils

### Installation (macOS)
```brew tap dferndz/formulae```  
```brew install cpp-utils```

### Usage
```
#include <utils.h>
#include <iostream>
#include <vector>

int main() {

  // print 10 numbers (0 - 9)
  for(auto n : range(10))
    std::cout << n << std::endl;
  
  // print 10 numbers (from 10 to 20, 20 not inclusive)
  for(auto n : range(10, 20))
    std::cout << n << std::endl;
  
  // print numbers from 0 - 9
  foreach(range(10), [] (int n) {
    std::cout << n << std::endl;
  });
  
  // generate a vector of random numbers (10 numbers less than 20)
  auto nums = rand_list<std::vector<int>>(10, 20);
  
  // print elements of nums as int separated by a space and add an endl after printing all numbers
  foreach(nums, helpers::print<int, ' '>, helpers::endl);

  // print 10 random numbers between 40 and 30 (max number not inclusive)
  foreach(range<random_itr<40, 30>>(10), helpers::print<int, ' '>, helpers::endl);
}
```
