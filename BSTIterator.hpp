#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:
  BSTNode<Data>* curr; // pointer to this BSTIterator's current BSTNode

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ //DONE
  BSTIterator(BSTNode<Data>* curr) {
    this->curr = curr;
  }

  /** Dereference operator.
   *  Return a copy of the Data item in the current BSTNode.
   */
  Data operator*() const {
    return curr->data;
  }
  
  /** Pre-increment operator.
   *  Update this BSTIterator to point to the inorder successor of the current
   *  BSTNode, and return a reference to the updated BSTIterator.
   */
  BSTIterator<Data>& operator++() {
    curr = curr->successor();
    return *this;
  }

  /** Post-increment operator. 
   *  Update this BSTIterator to point to the inorder successor of the current
   *  BSTNode, and return a copy of the old, non-updated BSTIterator.
   */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  /** Equality test operator. */ //DONE
  bool operator==(BSTIterator<Data> const & other) const {
    return (this->curr==other.curr);
  }

  /** Inequality test operator. */ //DONE
  bool operator!=(BSTIterator<Data> const & other) const {
    return !(this->curr==other.curr);
  }

};

#endif //BSTITERATOR_HPP
