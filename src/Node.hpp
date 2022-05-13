#ifndef _NODEHPP_
#define _NODEHPP_

template<class Key>
class BNode {

 public:

  BNode(const Key& k){ data_ = k; }

  void setData(const Key& k){data_ = k;}
  Key getData(){ return data_; }

  bool isLeftChildrenEmpty(){ return (lChildren_ == nullptr) ? true : false; }
  bool isRightChildrenEmpty(){ return (rChildren_ == nullptr) ? true : false; }

  void setLeftChildren(BNode<Key>* node){ lChildren_ = node;}
  void setRightChildren(BNode<Key>* node){ rChildren_ = node;}

  BNode<Key>* getLeftChildren(){return lChildren_;}
  BNode<Key>* getRightChildren(){return rChildren_;}

 private:
  Key data_;
  BNode<Key>* lChildren_ = nullptr;
  BNode<Key>* rChildren_ = nullptr;

};

#endif /* _NODEHPP_ */
