#include <iostream>
#include <algorithm>
#include <array>
#include "../library/sort/BubbleSort.h"
#include "../library/math/Print.h"
#include "../library/sort/Filter.h"
#include "../library/sort/SelectionSort.h"
#include "../library/sort/QuickSort.h"
#include "../library/sort/MaxHeap.h"
#include "../library/sort/CountingSort.h"
#include "../library/sort/RadixSort.h"

int main(void)
{
/**********test bubble sort...*************************/
  {
    std::cout << "Test #1: Bubble Sort" << std::endl;
    int array[] = {9, 8, 5, 6, 7, 8 , 3, 2, 1, 10, 4};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Starting Array: ";
    Print::array(array, size);
    Sort::BubbleSort::sort(array, size);
    std::cout << "Ending array: ";
    Print::array(array, size);
  }
/**********test remove duplicates filter...**************/
  {
    std::cout << "Test #2: Filter, Remove Duplicates" << std::endl;
    int array[] = {1, 1, 2, 1, 4, 5, 6, 7, 7, 6, 6, 5, 1, 3, 2};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Starting Array: ";
    Print::array(array, size);
    size = Filter::removeDuplicates(array, size);
    std::cout << "Ending Array: ";
    Print::array(array, size);
  }
/**********test Selection Sort...*************************/
  {
    std::cout << "Test #3: Selection Sort" << std::endl;
    int array[] = {1, 1, 2, 1, 4, 5, 6, 7, 7, 6, 6, 5, 1, 3, 2};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Starting Array: ";
    Print::array(array, size);
    Sort::SelectionSort::sort(array, size);
    std::cout << "Ending Array: ";
    Print::array(array, size);
  }

/**********test Quick Sort...*************************/
  {
    std::cout << "Test #4: Quick Sort" << std::endl;
    int array[] = {1, 1, 2, 1, 4, 5, 6, 7, 7, 6, 6, 5, 1, 3, 2};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Starting Array: ";
    Print::array(array, size);
    Sort::QuickSort::sort(array, size);
    std::cout << "Ending Array: ";
    Print::array(array, size);
  }

/**********test Heap Sort...*************************/
  {
    std::cout << "Test #5: Heap Sort" << std::endl;
    int array[] = {1, 1, 2, 1, 4, 5, 6, 7, 7, 6, 6, 5, 1, 3, 2};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Starting Array: ";
    Print::array(array, size);
    MaxHeap<int> heap(array, size);
    heap.sort();
    std::cout << "Ending Array: ";
    heap.print();
  }

/**********test Counting Sort...*************************/
  {
    std::cout << "Test #6: Counting Sort" << std::endl;
    int array[] = {1, 1, 2, 1, 4, 5, 6, 7, 7, 6, 6, 5, 1, 3, 2};
    size_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Starting Array: ";
    Print::array(array, size);
    Sort::CountingSort::sort(array, size);
    std::cout << "Ending Array: ";
    Print::array(array, size);
  }

/**********test Radix Sort...*************************/
  {
    std::cout << "Test #7: Radix Sort" << std::endl;
    int array[] = {101021, 231, 999, 1000, 4, 12, 106, 9981, 12345, 1234, 12347, 10, 9, 3, 2};
    size_t base(10);
    size_t size = sizeof(array) / sizeof(array[0]);
    std::cout << "Starting Array: ";
    Print::array(array, size);
    Sort::RadixSort::sort(array, size, base);
    std::cout << "Ending Array: ";
    Print::array(array, size);
  }

/**********test C++ Sort...*************************/
  {
    std::cout << "Test #7: C++ Sort" << std::endl;
    std::array<int,15> array = {101021, 231, 999, 1000, 4, 12, 106, 9981, 12345, 1234, 12347, 10, 9, 3, 2};
    std::cout << "Starting Array: ";
    Print::array(array.data(), array.size());
    std::sort(array.begin(), array.end());
    std::cout << "Ending Array: ";
    Print::array(array.data(), array.size());
    std::cout << "Reverse Array: ";
    std::sort(array.begin(), array.end(), std::greater<int>());
    Print::array(array.data(), array.size());
  }
}
