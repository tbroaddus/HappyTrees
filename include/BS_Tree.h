/*
 * TODO:
 *  - Build without compilation errors or warning.
 *    - Make CMakeLists file.
 *  - Define traversal functions.
 *  - Test insertion function.
 */

#ifndef BS_TREE_H
#define BS_TREE_H

#include "BaseTree.h"
#include "BinaryNode.h"

namespace HT {

template<class T>
class BS_Tree : public BaseTree<T> {

  public:

    // Default constructor
    BS_Tree();

    // Copy Constructor
    BS_Tree(const BS_Tree<T>& _tree) = default;

    // TODO May define later
    // Move Constructor
    //BS_Tree(BS_TREE<T>&& _tree);

    // Destructor
    ~BS_Tree() override = default;

    // Copy assignment operator
    BS_Tree<T>& operator=(const BS_Tree<T>& _tree) = default;

    // TODO May define later
    // Move assignment operator
    //BS_Tree<T>&& operator=(BS_Tree<T>&& _tree);

    // std::shared_ptr<BaseNode<T>> get(const T _item) override;

    std::shared_ptr<BaseNode<T>> insert(const T _item) override;

    // std::shared_ptr<BaseNode<T>> remove(const T _item) override;

    // const Status contains(const T _item) const override;

    // Prints elements in post order convention
    void postOrder() const;

    // Prints elements in preorder convention
    void preOrder() const;

    // Prints elements in in order convention
    void inOrder() const;

    int getSize() const override;

  private:

    // Private Recursive Functions

    std::shared_ptr<BaseNode<T>> insertRec (
        std::shared_ptr<BinaryNode<T>>& _root, const T _item);

    void postOrderRec(const std::shared_ptr<BinaryNode<T>>& _root) const;

    void preOrderRec(const std::shared_ptr<BinaryNode<T>>& _root) const;

    void inOrderRec(const std::shared_ptr<BinaryNode<T>>& _root) const;


    

    std::shared_ptr<BinaryNode<T>> root;

};


template<class T>
BS_Tree<T>::BS_Tree() : root(nullptr) {}


// TODO Define later.. convert from default
/*
template<class T>
BS_Tree::BS_Tree(const BS_Tree<T>& _tree) {}
*/


// TODO Define later.. convert from default
/*
template<class T>
BS_Tree::~BS_Tree() {}
*/

// TODO Define later.. convert from default
/*
template<class T>
BS_Tree<T>& BS_Tree::operator=(const BS_Tree<T>& _tree) {}
*/

/*
template<class T>
std::shared_ptr<BaseNode<T>> BS_Tree<T>::get(const T _item) {}
*/

// Notice: I am using this pointer to call insertrec function
template<class T>
std::shared_ptr<BaseNode<T>> BS_Tree<T>::insert(const T _item) {
  this->size++;
  std::cout << "insert(" << _item << ")" << std::endl;
  if (root == nullptr) {
    root = std::make_shared<BinaryNode<T>>();
    root->item = _item;
    return root;
  }
  else if (_item <= root->item) {
    return this->insertRec(root->left_node, _item);
  }
  else {
    return this->insertRec(root->right_node, _item);
  }
}


// Notice: I am using this pointer to call insertrec function
template<class T>
std::shared_ptr<BaseNode<T>> BS_Tree<T>::insertRec (
    std::shared_ptr<BinaryNode<T>>& _root, const T _item) {
  if (_root == nullptr) {
    _root = std::make_shared<BinaryNode<T>>();
    _root->item = _item;
    return _root;
  }
  else if (_item <= _root->item) {
    return this->insertRec(_root->left_node, _item);
  }
  else {
    return this->insertRec(_root->right_node, _item);
  }
}

/*
template<class T>
std::shared_ptr<BaseNode<T>> BS_Tree<T>::remove(const T _item) {}
*/

/*
template<class T>
const Status BS_Tree<T>::contains(const T _item) const {}
*/

template<class T>
void BS_Tree<T>::postOrder() const {
  if (root == nullptr) {
    return; 
  }
  postOrderRec(root->left_node);
  postOrderRec(root->right_node);
  std::cout << root->item << std::endl;
}


template<class T>
void BS_Tree<T>::preOrder() const {
  if (root == nullptr) {
    return;
  }
  std::cout << root->item << std::endl;
  preOrderRec(root->left_node);
  preOrderRec(root->right_node);
}


template<class T>
void BS_Tree<T>::inOrder() const {
  if (root == nullptr) {
    return;
  }
  inOrderRec(root->left_node);
  inOrderRec(root->right_node);
}


template<class T>
void BS_Tree<T>::postOrderRec(const std::shared_ptr<BinaryNode<T>>& _root) const {
  if (_root == nullptr) {
    return;
  }
  postOrderRec(_root->left_node);
  postOrderRec(_root->right_node);
  std::cout << _root->item << std::endl;
}


template<class T>
void BS_Tree<T>::preOrderRec(const std::shared_ptr<BinaryNode<T>>& _root) const {
  if (_root == nullptr) {
    return;
  }
  std::cout << _root->item << std::endl;
  preOrderRec(_root->left_node);
  preOrderRec(_root->right_node);
}


template<class T>
void BS_Tree<T>::inOrderRec(const std::shared_ptr<BinaryNode<T>>& _root) const {
  if (_root == nullptr) {
    return;
  }
  inOrderRec(_root->left_node);
  std::cout << _root->item << std::endl;
  inOrderRec(_root->right_node);
}

template<class T>
int BS_Tree<T>::getSize() const {
  return this->size;
}


} // end of namespace HT
#endif
