#include <iostream>

#include "BS_Tree.h"

using std::cout;
using std::endl;

int main() {

  HT::BS_Tree<int> bin_tree;
  bin_tree.insert(4);
  bin_tree.insert(2);
  bin_tree.insert(6);
  bin_tree.insert(-1);
  bin_tree.insert(2);
  bin_tree.insert(5);
  bin_tree.insert(1);

  cout << "Pre order: " << endl;
  bin_tree.preOrder();
  cout << "In order: " << endl;
  bin_tree.inOrder();
  cout << "Post order: " << endl;
  bin_tree.postOrder();
  std::cout << "Size: " << bin_tree.getSize() << std::endl;

}
