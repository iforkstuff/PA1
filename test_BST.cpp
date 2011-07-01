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

  /* Create an STL vector of some ints */
  vector<int> v;
  v.push_back(3);
  v.push_back(4);
  v.push_back(1);
  v.push_back(100);
  v.push_back(-33);
  v.push_back(1468);
  v.push_back(446);
  v.push_back(163);
  v.push_back(701);
  v.push_back(89);
  v.push_back(1702);
  v.push_back(1689);
  v.push_back(949);
  v.push_back(1828);
  v.push_back(1730);
  v.push_back(1556);
  v.push_back(1613);
  v.push_back(1096);
  v.push_back(1804);
  v.push_back(108);
  v.push_back(506);
  v.push_back(1264);
  v.push_back(1484);
  v.push_back(768);
  v.push_back(1891);
  v.push_back(1379);
  v.push_back(1500);
  v.push_back(815);
  v.push_back(1332);
  v.push_back(1336);
  v.push_back(1864);
  v.push_back(1418);
  v.push_back(868);
  v.push_back(847);
  v.push_back(484);
  v.push_back(262);
  v.push_back(1104);
  v.push_back(1129);
  v.push_back(323);
  v.push_back(478);
  v.push_back(1580);
  v.push_back(621);
  v.push_back(812);
  v.push_back(828);
  v.push_back(1316);
  v.push_back(866);
  v.push_back(1036);
  v.push_back(1411);
  v.push_back(287);
  v.push_back(683);
  v.push_back(1726);
  v.push_back(1042);
  v.push_back(21);
  v.push_back(1414);
  v.push_back(437);
  v.push_back(1249);
  v.push_back(704);
  v.push_back(1637);
  v.push_back(-53);
  v.push_back(1644);
  v.push_back(735);
  v.push_back(328);
  v.push_back(783);
  v.push_back(1003);
  v.push_back(1586);
  v.push_back(1465);
  v.push_back(239);
  v.push_back(376);
  v.push_back(1651);
  v.push_back(512);
  v.push_back(740);
  v.push_back(681);
  v.push_back(1464);
  v.push_back(1621);
  v.push_back(1838);
  v.push_back(411);
  v.push_back(46);
  v.push_back(1706);
  v.push_back(34);
  v.push_back(530);
  v.push_back(477);
  v.push_back(1428);
  v.push_back(285);
  v.push_back(407);
  v.push_back(184);
  v.push_back(979);
  v.push_back(1110);
  v.push_back(432);
  v.push_back(741);
  v.push_back(1837);
  v.push_back(308);
  v.push_back(1403);
  v.push_back(1796);
  v.push_back(1469);
  v.push_back(1617);
  v.push_back(1413);
  v.push_back(1634);
  v.push_back(1729);
  v.push_back(1292);
  v.push_back(1517);
  v.push_back(883);


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
    cout << *it << endl;
    if(*it != *vit) {
      cout << "Incorrect inorder iteration of BST." << endl;
      return -1;
    }
    ++vit;
  }

}
