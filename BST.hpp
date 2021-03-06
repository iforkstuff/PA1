/** Authors:
 *  Aria Arasteh, aarasteh, A08557093
 *  David Yoo, dayoo, A07865444
 */
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
   */ // DONE
  virtual BSTNode<Data>* newNode(const Data & item) {
    BSTNode<Data>** curr = &root;           //The current node pointer
    BSTNode<Data>* parent = NULL;           //The current's parent
    
    /* Find out where to insert the new node, or return NULL if duplicate */
    while ((*curr)!=NULL) {
      parent = *curr;
      if ((*curr)->data == item) {
        return NULL;
      } else if (item < (*curr)->data) {
        curr = &((*curr)->left);
      } else {
        curr = &((*curr)->right);
      }
    }
    
    (*curr) = new BSTNode<Data>(item);
    (*curr)->parent = parent;

    return *curr;    
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
   */ // DONE
  virtual ~BST() {
	  destroy(root);
    root = NULL;
		return;  
  }

  /** Insert a Data item in the BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if the item was already in this BST.
   */
  virtual bool insert(const Data& item) {
    BSTNode<Data> *n = newNode(item);
    if(0 == n) return false;
    isize++;    
    repair(n);
    return true;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ // DONE
  iterator find(const Data& item) const {
    BSTNode<Data> * curr = root;    //The current node.
     
    
    /* Traverse the tree in search of a BSTNode containing item. */
    while (curr!=NULL && curr->data!=item) {
      if (curr->data > item) {
        curr = curr->left;
      } else {
        curr = curr->right;
      }
    }

    return typename BST<Data>::iterator(curr);
  }

  
  /** Return the number of items currently in the BST.
   */ // DONE
  unsigned int size() const {
    return isize;
  }

  /** Return true if the BST is empty, else false.
   */ // DONE
  bool empty() const {
	  if (isize == 0)
		  return true;
	  
	  return false;
  }

  /** Return an iterator pointing to the first item in the BST.
   */ // DONE
  iterator begin() const {
    BSTNode<Data> * curr = root;
    
    if (curr!=NULL) {
      while (curr->left!=NULL) {
        curr = curr->left;
      }
    }
    
    return typename BST<Data>::iterator(curr);
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }
  
private:
  
  /* Recursively destroy the subtree. Setting parent, left, and right to NULL
     may not be strictly necessary, but may help diagnose dangling pointers. */
  static void destroy(BSTNode<Data> * sRoot) {
    if (sRoot != NULL) {
      destroy(sRoot->left);
      sRoot->left = NULL;
      destroy(sRoot->right);
      sRoot->right = NULL;
      sRoot->parent = NULL;
      delete sRoot;
    }
    
    return;
  }

 };


#endif //BST_HPP
