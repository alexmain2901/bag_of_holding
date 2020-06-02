#include <iostream>
#include "../library/BubbleSort.h"
#include "../library/Print.h"
#include "../library/Filter.h"
#include "../library/SelectionSort.h"
#include "../library/QuickSort.h"
#include "../library/MaxHeap.h"

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
}
