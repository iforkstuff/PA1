#ifndef BSTNODE_HPP
#define BSTNODE_HPP


template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d): data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  int info;  // instance variable used in advanced algorithms 
  const Data  data;

  /** Return the inorder successor of this BSTNode in a BST, or 0 if none.
   *  PRECONDITION: this BSTNode is a node in a BST.
   *  POSTCONDITION:  the BST is unchanged.
   *  RETURNS: the BSTNode that is the inorder successor of this BSTNode,
   *  or 0 if there is none.
   */ // TODO
  BSTNode<Data>* successor() {
    
    if (right!=NULL) {
      return right;
    } else if (parent==NULL) {
      return NULL;
    } else if (this==parent->left) {
      return parent;
    } else {
      return parent.ancestralSuccessor();
    }
  }
  
  BSTNode<Data>* ancestralSuccessor() {
    if (parent==NULL) {
      return NULL;
    } else if (this!=parent->left) {
      return parent;
    } else {
      return parent->ancestralSuccessor();
    }
  }
  
  
}; 

#endif // BSTNODE_HPP
