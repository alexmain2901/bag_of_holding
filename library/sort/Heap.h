#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstdlib>
#include <vector>

template <class T>
class Heap
{

protected:
  typedef typename std::vector<T>::iterator iterator;
  iterator begin(){ return m_heap.begin(); }
  iterator end(){ return m_heap.end(); }

  Heap(){}
  Heap(T *array, size_t size); 
  size_t parent(size_t node);
  size_t child_left(size_t node);
  size_t child_right(size_t node);
  int get(size_t node, T &value);
  int set(size_t node, T value);
  void push_back(T value){ m_heap.push_back(value); }
  size_t size(){ return m_heap.size(); }
  virtual void sort() = 0;
  virtual void insert(T value) = 0;
  virtual void remove(T value) = 0;
  virtual void print(std::string sep=" ");
  std::vector<T> m_heap;
};

template <class T>
Heap<T>::Heap(T *array, size_t size)
{
  for(size_t i(0); i < size; ++i)
  {
    m_heap.push_back(array[i]);
  }
}

template <class T>
size_t Heap<T>::parent(size_t node)
{
  if(node == 0)
  {
    return 0;
  }
  
  return (node - 1) / 2;
}

template <class T>
size_t Heap<T>::child_left(size_t node)
{
  return (node * 2) + 1;
}

template <class T>
size_t Heap<T>::child_right(size_t node)
{
  return (node * 2) + 2;
}

template <class T>
int Heap<T>::get(size_t node, T &value)
{
  if(node < m_heap.size())
  {
    value = m_heap[node];
    return 0;
  }

  return -1;
}

template <class T>
int Heap<T>::set(size_t node, T value)
{
  if(node < m_heap.size())
  {
    m_heap[node] = value;
    return 0;
  }

  return -1;
}

template <class T>
void Heap<T>::print(std::string sep)
{
  for(size_t i(0); i < m_heap.size(); ++i)
  {
    std::cout << m_heap[i] << sep;
  }

  std::cout << std::endl;
}

#endif
