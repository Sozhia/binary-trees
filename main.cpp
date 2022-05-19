#ifndef _MAINCPP_
#define _MAINCPP_

#include <string.h>
#include <stdio.h>
#include <iostream>
#include "./src/Node.hpp"
#include "./include/BinaryTree.hpp"
#include "./src/BalancedBinaryTree.hpp"
#include "./src/SearchBinaryTree.hpp"


void printHelp();
char askTreeType();
void startProgram(char option);
void balancedBinaryTreeMenu();
void searchBinaryTreeMenu();
char askOptionBalancedBinaryTree();
char askOptionSearchBinaryTree();
void insertKey(BinaryTree<int>* &tree);
void findKey(BinaryTree<int>* &tree);

int main(int argc, char** argv) {
  if (argc == 2 && strcmp(argv[1], "--help")==0) {
    printHelp();
  }
  if (argc != 1) {
    std::cout << "\t Try ./binary-trees --help for more information."<< std::endl;
  } else {
    char t = askTreeType();
    startProgram(t);
  }
  exit(1);
  return 0;
}

char askTreeType(){
  char option;
  std::cout << "\t Please enter a value between 0 - 2. Otherwise program will shutdown:"<< std::endl;
  std::cout << "\t\t [0].- Exit the program."<< std::endl;
  std::cout << "\t\t [1].- Balanced Binary Tree."<< std::endl;
  std::cout << "\t\t [2].- Binary Search Tree."<< std::endl;
  std::cin >> option;
  return option;
}

void startProgram(char option){
  switch(option){
    case '1':
      balancedBinaryTreeMenu();
      break;
    case '2':
      searchBinaryTreeMenu();
      break;
    default:
      std::cout << "Exiting program!" << std::endl;
      exit(0);
      break;
  }
}

void balancedBinaryTreeMenu(){

  int rootValue;
  BinaryTree<int>* tree = new BalancedBinaryTree<int>;

  std::cout << *tree << std::endl;
  std::cout << "\t Enter a value to insert as root.."<< std::endl;
  std::cin >> rootValue;

  tree->insert(rootValue);

  std::cout << *tree << std::endl;
  char option = askOptionBalancedBinaryTree();

  while(option != '0') {

    switch(option){
      case '1':
        insertKey(tree);
        std::cout << *tree << std::endl;
        break;

      case '2':
        findKey(tree);
        break;

      case '3':
        tree->askTraversal();
        break;

      default:
        std::cout << "Invalid option" << std::endl;
        break;
    }

    option = askOptionBalancedBinaryTree();

  }
  std::cout << "\t Exiting program."<< std::endl;
}

char askOptionBalancedBinaryTree(){
  char option;
  std::cout << "\t Please enter a value between 0 - 3. Otherwise program will shutdown:"<< std::endl;
  std::cout << "\t\t [0].- Exit the program."<< std::endl;
  std::cout << "\t\t [1].- Insert Key ~ Try to add a node to the tree."<< std::endl;
  std::cout << "\t\t [2].- Find key ~ Look for an specified key."<< std::endl;
  std::cout << "\t\t [3].- Tree traversal."<< std::endl;
  std::cin >> option;
  return option;
}

void searchBinaryTreeMenu(){
  
  int rootValue;
  BinaryTree<int>* tree = new SearchBinaryTree<int>;
  std::cout << *tree << std::endl;
  std::cout << "\t Enter a value to insert as root.."<< std::endl;
  std::cin >> rootValue;
  tree->insert(rootValue);
  std::cout << *tree << std::endl;
  char option = askOptionSearchBinaryTree();

  while(option != '0') {

    switch(option){
      case '1':
        insertKey(tree);
        std::cout << *tree << std::endl;
        break;

      case '2':
        findKey(tree);
        break;

      case '3':
        int value;
        std::cout << "\t Enter a value to delete as key.."<< std::endl;
        std::cin >> value;
        tree->erase(value);
        break;

      case '4':
        tree->askTraversal();
        break;

      default:
        std::cout << "Invalid option" << std::endl;
        exit(0);
        break;
    }

    option = askOptionSearchBinaryTree();

  }
  std::cout << "\t Exiting program."<< std::endl;
}

char askOptionSearchBinaryTree(){
  char option;
  std::cout << "\t Please enter a value between 0 - 3. Otherwise program will shutdown:"<< std::endl;
  std::cout << "\t\t [0].- Exit the program."<< std::endl;
  std::cout << "\t\t [1].- Insert Key ~ Try to add a node to the tree."<< std::endl;
  std::cout << "\t\t [2].- Find key ~ Look for an specified key."<< std::endl;
  std::cout << "\t\t [3].- Delete Key"<< std::endl;
  std::cout << "\t\t [4].- Tree traversal."<< std::endl;
  std::cin >> option;
  return option;
}

void insertKey(BinaryTree<int>* &tree){
  int value = 0;
  std::cout << "Enter a key to insert:"<< std::endl;
  std::cin >> value;
  if(!tree->insert(value)) {
    std::cout << "Key already in use." << std::endl;
    return;
  }
  std::cout << "Succes!" << std::endl;
}

void findKey(BinaryTree<int>* &tree){
  int value = 0;
  std::cout << "Enter a key to search:"<< std::endl;
  std::cin >> value;
  if(!tree->search(value)){
    std::cout << "Key not found." << std::endl;
    return;
  }
  std::cout << "Key found!"<< std::endl;

}

void printHelp() {
    std::cout << "This is an implementation of a simple {forced} balanced binary tree"<< std::endl;
    std::cout << "in the C++ programming language for academic purposes."<< std::endl;
    std::cout << "To run the program in your local machine check out the following steps:"<< std::endl;
    std::cout << "\t 1.- ./binary-tree "<< std::endl;
    std::cout << "\t 2.- You must select the option in the menu:"<< std::endl;
    std::cout << "\t\t [0].- Exit the program."<< std::endl;
    std::cout << "\t\t [1].- Insert Key ~ Try to add a node to the tree."<< std::endl;
    std::cout << "\t\t [2].- Find key ~ Look for an specified key. Returns boolean."<< std::endl;
    std::cout << "\t\t [3].- Tree traversal: inOrder."<< std::endl;
}

#endif /* _MAINCPP_ */