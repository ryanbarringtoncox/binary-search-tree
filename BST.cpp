#include "BST.h"
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
	Node<T>** curr =&root;
	
	while(*curr!=0 && (*curr)->getValue()!= v) {
		if (v < (*curr)->getValue()) {
			curr = &((*curr)->getLeftChild());
		} else if (v > (*curr)->getValue()) {
			curr = &((*curr)->getRightChild());
		}    
	}
	
	if (*curr==0) {
		return false;
	}
	else {
		return true;
	}
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** curr =&root;
  Node<T>* parent;
	
  //is v in tree?
  while(*curr!=0 && (*curr)->getValue()!= v) {
	  parent = *curr;	  
	  if (v < (*curr)->getValue()) {
		  curr = &((*curr)->getLeftChild());
	  } else if (v > (*curr)->getValue()) {
		  curr = &((*curr)->getRightChild());
	  }    
  }
	
  //v not found
  if (*curr==0) {
	cout << v << " is not in this tree." <<endl;
	return;
  }
	
  //v is Found
  else if ((*curr)->getValue()==v) {
	cout << "Found " << v << endl;	
	
	//if node has no children, simply remove
	if ((*curr)->getLeftChild()==0 && (*curr)->getRightChild()==0) {
	  cout << v << " is a leaf" << endl;
	  cout << "Parent is " << parent->getValue() << endl;
	  //if (parent->getValue()>(*curr)->getValue())
		  //parent->setLeftChild(0);
	}
	
    //if right child exists, get in-order successor
	  
	//if only left child exists, cut out v node
  }
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
