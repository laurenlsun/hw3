#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <functional>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap : private std::vector<T>
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

private:
  /// Add whatever helper functions and data members you need below
  int m;
  PComparator c;
};

// Add implementation of member functions here


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
    throw std::underflow_error("Called top on empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return std::vector<T>::front();
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
    throw std::underflow_error("Called pop on empty heap");
  }

  // put last at the top
  std::vector<T>::at(0) = std::vector<T>::back();
  // delete biggest item
  std::vector<T>::pop_back();
  bool done = false; // done when top is better than all of its children
  int curr = 0; // current index
  while((!done) && (curr*m+1<std::vector<T>::size())) {
    // done if curr is a leaf node

    // find largest child
    // set best by as first child
    T best = std::vector<T>::at(curr*m+1);
    int bestindex = curr*m+1; // index of best child
    // loop through child indices up to whatever is within range
    int stopindex;
    if (curr*m+m+1 < std::vector<T>::size()) // not missing any children
      stopindex = curr*m+m+1;
    else
      stopindex = std::vector<T>::size(); // array stops before all children; some children missing

    for (int i=curr*m+1; i<stopindex; i++) {
      // if child better than current best
      if (c(std::vector<T>::at(i), best)) {
        // set child as new best
        best = std::vector<T>::at(i);
        bestindex = i;
      }
    }
    // found best child, now compare to parent
    if (c(best, std::vector<T>::at(curr))) {
      // child is better; swap
      T temp = best;
      std::vector<T>::at(bestindex) = std::vector<T>::at(curr);
      std::vector<T>::at(curr) = temp;

      // item now in best index
      curr = bestindex;
    }
    else // parent is better than all children; done
      done = true;
  }

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  std::vector<T>::push_back(item);

  // trickle up

  int curr = std::vector<T>::size()-1;
  bool done = false; // done when worse than its parent

  while((!done) && (curr!=0)) {
    if(c(item, std::vector<T>::at((curr-1)/m))) {
      // item better than its parent; swap

      std::vector<T>::at(curr) = std::vector<T>::at((curr-1)/m);
      std::vector<T>::at((curr-1)/m) = item;
      curr = (curr-1)/m;
    }
    else // worse than its parent; done trickling up
      done = true;
  }

}


template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return std::vector<T>::empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return std::vector<T>::size();
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : std::vector<T>(),  m(m), c(c) {

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}


#endif

