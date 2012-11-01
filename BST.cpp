#include "BST.h"
#include <iostream>
#include <list>
using namespace std;
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
	
  //is v in tree?
  while(*curr!=0 && (*curr)->getValue()!= v) {
	  if (v < (*curr)->getValue()) {
		  curr = &((*curr)->getLeftChild());
	  } else if (v > (*curr)->getValue()) {
		  curr = &((*curr)->getRightChild());
	  }    
  }
	
  //v not found
  if (*curr==0) {
	return;
  }
	
  //v is Found
  else {
	Node<T>* nodeToRemove = *curr;	
	//no left child
	if ((nodeToRemove)->getLeftChild()==0) {
		*curr=nodeToRemove->getRightChild();
	}
	//if there's a left child find in-order-predecessor
	else {
		Node<T>* iop = nodeToRemove->getLeftChild();
		while (iop->getRightChild()!=0) {
		  iop = iop->getRightChild();	
		}
		iop->setRightChild(*(nodeToRemove->getRightChild()));
		*curr=nodeToRemove->getLeftChild();
	}	  
	delete nodeToRemove;
  }
}

template <typename T>
void BST<T>::visualPrint() {
	list<Glob<T>*> q;
	int level=0;
	Glob<T>* curr = new Glob<T>(*root, level);
	q.push_back (curr);
	Node<T>* curr_node;
	while (!(q.empty())) {
		//level++;		
		Glob<T>* curr_glob = q.front();
		curr_node = curr_glob->getNodePointer();
		if (curr_node->getLeftChild()!=0) {
			level = (curr_glob->getLevel())+1;
			Glob<T>* new_glob_left = new Glob<T>(*(curr_node->getLeftChild()), level);
			q.push_back (new_glob_left);
		}
		if (curr_node->getRightChild()!=0) {
			level=(curr_glob->getLevel())+1;
			Glob<T>* new_glob_right = new Glob<T>(*(curr_node->getRightChild()), level);
			q.push_back (new_glob_right);
		}		
		//if (curr->getRightChild()!=0) q.push_back (curr->getRightChild());		
		if (curr_node!=0) {
			cout << "Curr glob level: " << curr_glob->getLevel() << endl;
			cout << "   value is: " << curr_glob->getNodePointer()->getValue() << endl;
			//g->getLevel()
		}
		q.pop_front();	
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
