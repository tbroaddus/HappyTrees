// Interface class for certain user defined tree structures


#ifndef BASETREE_H
#define BASETREE_H

#include <memory>

// Namespace for HT (HappyTrees)
namespace HT {

  
/*
 * Enumeration class for status value.
 */
enum class Status {NotFound, Found};


template<class T>
class BaseTree {

  public:

    // Default Constructor
    virtual BaseTree();

    // Copy Constructor
    virtual BaseTree(const BaseTree<T>& _tree);

    // TODO may define later
    // Move Constructor
    // virtual BaseTree(BaseTree<T>&& _tree);

    // Destructor
    virtual ~BaseTree();

    // Copy Assignment Operator
    virtual BaseTree<T>& operator=(const BaseTree<T>& _tree);

    // TODO may define later
    // Move Assignment Operator
    // virtual BaseTree<T>& operator=(BaseTree<T>&& _tree);

    virtual std::shared_ptr<BaseNode<T>> get(const T _item);

    // Add item T to the next position in the tree 
    virtual std::shared_ptr<BaseNode<T>> insert(const T _item);

    // Remove item T from the tree 
    virtual std::shared_ptr<BaseNode<T>> remove(const T _item);

    // Set membership status of item in the tree 
    virtual const Status contains(const T _item) const;

    // Print size and contents of tree
    virtual void printInfo() const;

    

  protected:

    // Size of tree
    int size;
};


} // End of namespace HT

#endif
