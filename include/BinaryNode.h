#ifndef BINARYNODE_H
#define BINARYNODE_H

#include "BaseNode.h"

namespace HT {

template<class T>
struct BinaryNode : public BaseNode<T> {

  std::shared_ptr<BinaryNode<T>> left_node = nullptr;
  std::shared_ptr<BinaryNode<T>> right_node = nullptr;

};
}
#endif
