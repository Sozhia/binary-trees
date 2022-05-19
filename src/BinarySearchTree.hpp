#ifndef _BINARYSEARCHTREEHPP_
#define _BINARYSEARCHTREEHPP_

#include "../include/BinaryTree.hpp"
#include "./Node.hpp"  
#include <queue>
#include <iostream>

template<class Key>
class BinarySearchTree : public BinaryTree<Key>{
 public:
  BinarySearchTree(){}
  BinarySearchTree(const Key& k){ BinaryTree<Key>::getRoot() = addNode(k);}

  bool insert(const Key& k) {
    if (search(k)) return false;
    branchInsertion(k, BinaryTree<Key>::getRoot());
    return true;
  }

  bool search(const Key& k) { return branchSearch(k, BinaryTree<Key>::getRoot()); }

  bool erase(const Key& k) {
    if (!search(k)) return false;
    try{
      branchErase(k, BinaryTree<Key>::getRoot());
      return true;
    } catch (...){
      return false;
    }
  }

 private:
  
  int branchSearch(const Key& k, BNode<Key>* &node){
    if (node == nullptr) 
      return 0;
    if (k == node->getData()) 
      return 1;
    if (k < node->getData() )
      return branchSearch(k, node->getLeftChild());
    return branchSearch(k, node->getRightChild());
  }

  void branchInsertion(const Key& k, BNode<Key>* &node){
    if (node == nullptr)
      node = addNode(k);
    else if (k < node->getData())
      branchInsertion(k, node->getLeftChild());
    else
      branchInsertion(k, node->getRightChild());
  }

  void branchErase(const Key& k, BNode<Key>* &node){
    if (node == nullptr) 
      return;
    if (k < node->getData())
     branchErase(k, node->getLeftChild());
    else if (k > node->getData()) 
     branchErase(k, node->getRightChild());
    else {   //k == node_getData()
      BNode<Key>* temp = node;
      if (node->getRightChild() == NULL) 
        node = node->getLeftChild();
      else if (node->getLeftChild() == NULL)
        node = node->getRightChild();
      else 
        replacement(temp, node->getLeftChild());

      delete (temp);
    }   
  }

  void replacement(BNode<Key>* &deleted, BNode<Key>* &sust) {
    if (sust->getRightChild() != NULL) 
      replacement(deleted, sust->getRightChild());
    else {
      sust->setData(deleted->getData());
      deleted = sust ;
      sust = sust->getLeftChild() ;
    } 
  }

  BNode<Key>* addNode(const Key& k) const { 
    BNode<Key>* temp = new BNode<Key> (k);
    return temp; 
  }

};

#endif /* _BINARYSEARCHTREEHPP_ */