#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void trickleUp(int index);

  void trickleDown(int index);
  

private:
  /// Add whatever helper functions and data members you need below
  int leaves;
  PComparator comp;
  std::vector<T> v;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : leaves(m), comp(c) {

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  v.push_back(item);
  trickleUp(v.size() - 1);

}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The heap is empty!");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return v[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("The heap is empty!");
  }
  std::swap(v[0], v[v.size() - 1]);
  v.pop_back();
  trickleDown(0);

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  if (v.size() == 0) {
      return true;
  } else
      return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  size_t size = v.size();
  return size;

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int index){
  int parent = (index - 1)/leaves;

  if (index > 0 && comp(v[index], v[parent])) {
      std::swap(v[index], v[parent]);
      trickleUp(parent);
  } 

  else{
    return;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index){
  int child = leaves * index + 1;

  if (child >= (int)v.size()) {
      return;
  }

  else {

    int smallestChild = child;

    for (int i = child; i < index * leaves + leaves; i++) {
      if(i + 1 < (int)v.size()){
        if (comp(v[i + 1], v[smallestChild])) {
            smallestChild = i + 1;
        }
    }
    }

    if (comp(v[smallestChild], v[index])) {
        std::swap(v[smallestChild], v[index]);
        trickleDown(smallestChild);
    }
  }
}

#endif

