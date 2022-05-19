#ifndef _BINARYTREEHPP_
#define _BINARYTREEHPP_

#include "../src/Node.hpp"
#include <iostream>
#include <queue>

template<class Key> class BinaryTree{
 public:

  //Basic Operations
  virtual bool insert(const Key& k) = 0;
  virtual bool search(const Key& k) = 0;
  virtual bool erase(const Key& k) = 0;
  void askTraversal(){
    char option;
    std::cout << "\t Please enter a value between 0 - 3. Default inOrder"<< std::endl;
    std::cout << "\t\t [0].- inOrder."<< std::endl;
    std::cout << "\t\t [1].- preOrder."<< std::endl;
    std::cout << "\t\t [2].- postOrder."<< std::endl;
    std::cin >> option;
    switch (option) {
    case '0':
      inorder(root_);
      break;
    case '1':
      preorder(root_);
      break;
    case '2':
      postorder(root_);
      break;
    default:
      inorder(root_);
      break;
    }
  } 

  friend std::ostream& operator<<(std::ostream& os, const BinaryTree<Key>& tree){
    if (tree.getRoot() == nullptr){
      os << "[.]";
      return os;
    }

    std::queue<BNode<Key>*> parents;
    std::queue<BNode<Key>*> children;
    parents.push(tree.getRoot());
    int level = 0;
    while(!parents.empty() || !children.empty()){
      os << "Level " << level << ": ";
      while(!parents.empty()){
        if (parents.front() == nullptr)
          os << "[.]";
        else {
          os << "[" << parents.front()->getData() << "]";
          children.push(parents.front()->getLeftChild());
          children.push(parents.front()->getRightChild());
        }
        parents.pop();
      }
      while(!children.empty()){
        parents.push(children.front());
        children.pop();
      }
      os << std::endl;
      level ++;
    }
    return os;
  }
 
 private:
  //Tree traversal
  void  preorder(BNode<Key>* &node) const{
    if (node == nullptr){
      //std::cout << "[.]";
      return;
    }
    std::cout << "[" << node->getData() << "]";
    preorder(node->getLeftChild());
    preorder(node->getRightChild());
  }

  void  inorder(BNode<Key>* &node) const{
    if (node == nullptr){
      //std::cout << "[.]";
      return;
    }
    inorder(node->getLeftChild());
    std::cout << "[" << node->getData() << "]";
    inorder(node->getRightChild());
    
  }

  void  postorder(BNode<Key>* &node) const{
    if (node == nullptr){
      //std::cout << "[.]";
      return;
    }
    postorder(node->getLeftChild());
    postorder(node->getRightChild());
    std::cout << "[" << node->getData() << "]";
  }
 
 protected:
 /*Al devolver la referencia lo usamos para modificarlo. Si el retorno es valor
 constante lo usamos para no modificar. 
 Si la operacion que accede es constante usa la version const, en otro caso al &*/
  BNode<Key>*& getRoot() {return root_;}
  BNode<Key>* getRoot() const{return root_;}
  
 private:
  BNode<Key>* root_;
};

#endif /* _BINARYTREEHPP_ */
