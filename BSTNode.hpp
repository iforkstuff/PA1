/** Authors:
 *  Aria Arasteh, aarasteh, A08557093
 *  David Yoo, dayoo, A07865444
 */
#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#ifndef NULL
#define NULL 0L
#endif

template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d): data(d) {
    left = right = parent = NULL;
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
   */ // DONE
  BSTNode<Data>* successor() {
    /* Determine if the right child or parent is successor. If neither, and
       parent exists, find out if one of the parents ancestors is the successor.
       If no successor exists, return 0. */
    if (right!=NULL) {
      return right->leftmostNode();
    } else if (parent==NULL) {
      return NULL;
    } else if (this==parent->left) {
      return parent;
    } else {
      return parent->ancestralSuccessor();
    }
  }
  
  /** Return the leftmost node of the subtree.
   *  PRECONDITION: this BSTNode is a node in a BST.
   *  POSTCONDITION: the BST is unchanged.
   *  RETURNS: The BSTNode that is the leftmost node of the subtree.
   */
  BSTNode<Data>* leftmostNode() {    
    /* if this has a left child, recurse on that. Otherwise, return this. */
    if (left!=NULL) {
      return left->leftmostNode();
    } else {
      return this;
    }
  }
  
  
  /** Return the inorder ancestral successor of this BSTNode in a BST, or 
   *  0 if none.
   *  PRECONDITION:this BSTNode is a node in a BST.
   *  POSTCONDITION:  the BST is unchanged.
   *  RETURNS: the BSTNode that is the inorder ancestral successor of this 
   *  BSTNode, or 0 if there is none.
   */
  BSTNode<Data>* ancestralSuccessor() {
    /* Find and return a successor that is an ancestor, if it exists. */
    if (parent==NULL) {
      return NULL;
    } else if (this==parent->right) {
      return parent->ancestralSuccessor();
    } else {
      return parent;
    }
  }
  
  
}; 

#endif // BSTNODE_HPP
