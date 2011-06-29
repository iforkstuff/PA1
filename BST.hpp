#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"

template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Restore any required invariants after inserting a new Data item
   *  in this BST.  The argument should be a pointer to the node containing
   *  the Data item that was inserted.
   */
  virtual void repair(BSTNode<Data>* node) {}

  /** Given a Data item, insert it in this BST.  Return a pointer to
   *  the new BSTNode that holds the item, or 0 if the item was
   *  already in this BST.
   */ // TODO
  virtual BSTNode<Data>* newNode(const Data & item) {

  }


public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0)  {
  }


  /** Default destructor.
   *  Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
	  int i;
	  
	  if (isize == 0) {
		  return 0;
	  } else {
		  for (i=0; i < isize; i++) {
				delete 
		  }
	  }
		  
  }

  /** Insert a Data item in the BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if the item was already in this BST.
   */
  virtual bool insert(const Data& item) {
    BSTNode<Data> *n = newNode(item);
    if(0 == n) return false;
    repair(n);
    return true;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // TODO
  iterator find(const Data& item) const {
  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
	  if (isize == 0)
		  return true;
	  
	  return false;
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // TODO
  iterator begin() const {
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

 };


#endif //BST_HPP
