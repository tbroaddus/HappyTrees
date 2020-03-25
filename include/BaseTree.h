// Interface class for certain user defined tree structures

// TODO: Look at abstract classes

#ifndef BASETREE_H
#define BASETREE_H

#include <memory>
#include "BaseNode.h"

// Namespace for HT (HappyTrees)
namespace HT {

  
/*
 * Enumeration class for status value.
 */
enum class Status {NotFound, Found};


template<class T>
class BaseTree {

  public:

    // Destructor
    virtual ~BaseTree(){}

    // TODO may define later
    // Move Assignment Operator
    // virtual BaseTree<T>& operator=(BaseTree<T>&& _tree);

    // virtual std::shared_ptr<BaseNode<T>> get(const T _item);

    // Add item T to the next position in the tree 
    virtual std::shared_ptr<BaseNode<T>> insert(const T _item)=0;

    // Remove item T from the tree 
    // virtual std::shared_ptr<BaseNode<T>> remove(const T _item);

    // Set membership status of item in the tree 
    // virtual const Status contains(const T _item) const;

    virtual int getSize() const=0;
    // Print size and contents of tree
    // virtual void printInfo() const;

    

  protected:

    // Size of tree
    int size;
};

} // End of namespace HT

#endif
