#ifndef _BINARYTREEHPP_
#define _BINARYTREEHPP_

#include "../src/Node.hpp"
#include <iostream>

template<class Key> class BinaryTree{
 public:
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) = 0;
  virtual void inorder() const = 0;

  virtual void setRoot(BNode<Key>*) = 0;
  virtual BNode<Key>* getRoot() const = 0;
  virtual BNode<Key>* addNode(const Key& k) const = 0;
 // virtual int getMaxNodesPerLevel(unsigned int) const = 0;
 // virtual int getNumberOfNodes() const = 0;
 // virtual int getNumberOfLeaves() const = 0;
 
  friend std::ostream& operator<<(std::ostream&, const BinaryTree<Key>&);
  
 private:
  BNode<Key>* root_; // Default value
  // unsigned int height_ = 0, numNodes_ = 0;
};

#endif /* _BINARYTREEHPP_ */
