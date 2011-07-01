#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2010
 * Author: P. Kube (c) 2010
 */
int main() {

  vector<int> v;
  /* Create an STL vector of some ints */
#include "inserts.txt"

  /* Create an instance of BST holding int */
  BST<int> b;

  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return true
    if(! b.insert(*vit) ) {
      cout << "Incorrect return value when inserting " << *vit << endl;
      return -1;
    }
  }

  /* Test size. */
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout << "... which is incorrect." << endl;
    return -1;
  }

  /* Test find return value. */
  vit = v.begin();
  for(; vit != ven; ++vit) {
    if(*(b.find(*vit)) != *vit) {
      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }
  
  /* Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());

  /* Test BST iterator; should iterate inorder */
  cout << "traversal using iterator:" << endl;
  vit = v.begin();
  BST<int>::iterator en = b.end();
  BST<int>::iterator it = b.begin();
  for(; it != en; ++it) {
    if(*it != *vit) {
      cout << "Incorrect inorder iteration of BST." << endl;
      return -1;
    } 
    ++vit;
  }
  cout << "All elements matched sorted vector." << endl;


}
