#ifndef BS_TREE_H
#define BS_TREE_H

#include "BaseTree.h"
#include "BinaryNode.h"

namespace HT {

template<class T>
class BS_Tree : public BaseTree {

  public:

    // Default constructor
    BS_Tree();

    // Copy Constructor
    BS_Tree(const BS_Tree<T>& _tree);

    // TODO May define later
    // Move Constructor
    //BS_Tree(BS_TREE<T>&& _tree);

    // Destructor
    ~BS_Tree();

    // Copy assignment operator
    BS_Tree<T>& operator=(const BS_Tree<T>& _tree);

    // TODO May define later
    // Move assignment operator
    //BS_Tree<T>&& operator=(BS_Tree<T>&& _tree);

    std::shared_ptr<BinaryNode<T>> get(const T _item);

    std::shared_ptr<BinaryNode<T>> insert(const T _item);

    std::shared_ptr<BinaryNode<T>> remove(const T _item);

    const Status contains(const T _item) const;

  private:

    std::shared_ptr<BinaryNode<T>> root;

};


// TODO Define deafult constructor
template<class T>
BS_Tree() size{}



} // end of namespace HT
#endif
