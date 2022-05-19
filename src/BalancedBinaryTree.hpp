#ifndef _BALANCEDBINARYTREEHPP_
#define _BALANCEDBINARYTREEHPP_

#include "../include/BinaryTree.hpp"
#include "./Node.hpp"  
#include <queue>
#include <iostream>

template<class Key>
class BalancedBinaryTree : public BinaryTree<Key>{

 public:
  BalancedBinaryTree(){}

  BalancedBinaryTree(const Key& k) { BinaryTree<Key>::getRoot() = addNode(k); }

  bool insert(const Key& k){
    if (BinaryTree<Key>::getRoot() == nullptr){
      BinaryTree<Key>::getRoot() = addNode(k);
      return true;
    }

    if(!search(k)){
      equilibrateInsertion(k, BinaryTree<Key>::getRoot());
      return true;
    }
    return false;
  }

  bool search(const Key& k) {
    if (BinaryTree<Key>::getRoot() == nullptr)
      return false;

    std::queue<BNode<Key>*> q;
    q.push(BinaryTree<Key>::getRoot());

    while(!q.empty()){
      BNode<Key>* temp = q.front();
      q.pop();

      if(temp->getData() == k)
        return true;
      if(!temp->isLeftChildEmpty())
        q.push(temp->getLeftChild());
      if(!temp->isRightChildEmpty())
        q.push(temp->getRightChild());

    }
    return false;

  }

  bool erase(const Key& k){return false;}

 private:
  
  void equilibrateInsertion(const Key& k, BNode<Key>* &node){
    if (branchLength(node->getLeftChild()) <= branchLength(node->getRightChild())) {
      if (!node->isLeftChildEmpty())
        equilibrateInsertion(k, node->getLeftChild());
      else
        node->setLeftChild(addNode(k));
    } else {
      if (!node->isRightChildEmpty()) 
        equilibrateInsertion(k, node->getRightChild());
      else
        node->setRightChild(addNode(k));
    }
  }

  const int branchLength(BNode<Key>* &node) {
  if (node == nullptr) return 0;
  return (1 + branchLength(node->getLeftChild()) 
            + branchLength(node->getRightChild()) );
  }

  BNode<Key>* addNode(const Key& k) const { 
    BNode<Key>* temp = new BNode<Key> (k);
    return temp;
  }

};

#endif /* _BALANCEDBINARYTREEHPP_ */
