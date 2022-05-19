#ifndef _NODEHPP_
#define _NODEHPP_

template<class Key>
class BNode {

 public:

  BNode(const Key& k, BNode<Key>* l = NULL, BNode<Key>* r = NULL ){
    data_ = k;
    l = lChild_;
    r = rChild_;
  }

  void setData(const Key& k){data_ = k;}
  Key getData() const{ return data_; }

  bool isLeftChildEmpty(){ return (lChild_ == NULL) ? true : false; }
  bool isRightChildEmpty(){ return (rChild_ == NULL) ? true : false; }

  void setLeftChild(BNode<Key>* node) { lChild_ = node;}
  void setRightChild(BNode<Key>* node) { rChild_ = node;}

  BNode<Key>*& getLeftChild() {return lChild_;}
  BNode<Key>*& getRightChild() {return rChild_;}  

  ~BNode(){}

  BNode<Key>* operator=(const BNode<Key>* node){
    data_ = node->getData(); 
    lChild_ = node->getLeftChild();
    rChild_ = node->getRightChild();
    return *this;
  }

 private:
  Key data_;
  BNode<Key>* lChild_;
  BNode<Key>* rChild_;

};

#endif /* _NODEHPP_ */
