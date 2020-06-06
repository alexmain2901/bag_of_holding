#cmake_minimum_required (VERSION 2.6)
#project (bag_of_holding)
add_executable(run_10 problem10_summation_of_primes.cpp)
target_link_libraries(run_10 prime_lib)

add_executable(run_fizzbuzz fizzBuzz.cpp)

add_executable(run_12 problem12_triangle_numbers.cpp)

