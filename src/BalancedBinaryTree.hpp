#ifndef _BALANCEDBINARYTREEHPP_
#define _BALANCEDBINARYTREEHPP_

#include "../include/BinaryTree.hpp"
#include "./Node.hpp"
#include <math.h>  
#include <queue>
#include <iostream>

template<class Key>
class BalancedBinaryTree : public BinaryTree<Key>{

 public:
  BalancedBinaryTree(){}

  BalancedBinaryTree(const Key& k){ root_ = &BNode<Key>(k); }

  void setRoot(BNode<Key>* node) { root_ = node; }

  bool insert(const Key& k){
    if (root_ == nullptr){
      root_ = addNode(k);
      return true;
    }

    if(!search(k)){
      std::queue<BNode<Key>*> q;
      q.push(root_);
      
      while(!q.empty()){
        BNode<Key>* temp = q.front();
        q.pop();
        if(temp->isLeftChildrenEmpty()){
          temp->setLeftChildren(addNode(k));
          return true;
        }else{
          q.push(temp->getLeftChildren());
          if(temp->getRightChildren() == nullptr){
            temp->setRightChildren(addNode(k));
            return true;
          } else {
            q.push(temp->getRightChildren());
          }
        }
      }
    }
    return false;
  }

  bool search(const Key& k) {
    if (root_ == nullptr)
      return false;

    std::queue<BNode<Key>*> q;
    q.push(root_);

    while(!q.empty()){
      BNode<Key>* temp = q.front();
      q.pop();

      if(temp->getData() == k)
        return true;
      if(temp->getLeftChildren() != nullptr)
        q.push(temp->getLeftChildren());
      if(temp->getRightChildren() != nullptr)
        q.push(temp->getRightChildren());

    }
    return false;
   }

  void inorder() const{
    if (root_ == nullptr)
      return;
    std::cout << "Traversal tree (Inorder): ";
    printInorder(root_);
    std::cout << std::endl;
  }

  void printInorder(BNode<Key>* node) const{
    if (node == nullptr)
      return;
    printInorder(node->getLeftChildren());
    std::cout<< "[" << node->getData() << "] ";
    printInorder(node->getRightChildren());
  }

  BNode<Key>* getRoot() const { return root_; }

  BNode<Key>* addNode(const Key& k) const { 
    BNode<Key>* temp;
    temp->setData(k);
    return temp;
  }

 // int getMaxNodesPerLevel(unsigned int level) const {return (int)pow(2,level-1);}

 // int getNumberOfNodes() const {return ((int)pow(2,height_+1))-1;}

 // int getNumberOfLeaves() const {return maxNodesPerLevel(height_);}

  friend std::ostream& operator<<(std::ostream& os, const BinaryTree<Key>& tree){
    if (tree.getRoot() == nullptr){
      os << "[.]";
      return os;
    }

    std::queue<BNode<Key>*> parents;
    std::queue<BNode<Key>*> children;

    parents.push(tree.getRoot());
    while(!parents.empty() || !children.empty()){
      while(!parents.empty()){
        BNode<Key>* temp = parents.front();
        os << "[" << temp->getData() << "]";
        parents.pop();
        if(temp->getLeftChildren() != nullptr) children.push(temp->getLeftChildren());
        if(temp->getRightChildren() != nullptr) children.push(temp->getRightChildren());
      }
      while(!children.empty()){
        BNode<Key>* temp = children.front();
        os << "[" << temp->getData() << "]";
        children.pop();
        if(temp->getLeftChildren() != nullptr) parents.push(temp->getLeftChildren());
        if(temp->getRightChildren() != nullptr) parents.push(temp->getRightChildren());
      }
    }
    return os;
  }

 private:

  BNode<Key>* root_; // Default value
  // unsigned int height_ = 0, numNodes_ = 0;
};

#endif /* _BALANCEDBINARYTREEHPP_ */
