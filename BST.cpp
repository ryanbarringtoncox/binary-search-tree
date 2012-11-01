#include "BST.h"
#include <iostream>
#include <list>
#include <vector>
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
void BST<T>::visualPrint(T def, T leftLeg, T rightLeg) {
	cout << "Yer legs are " << leftLeg << " and " << rightLeg << endl;;
	//make a Queue of globs, push in root at 0, 0
	list<Glob<T>*> q;
	int level=0; int spread=0;
	Glob<T>* root_glob = new Glob<T>(*root, level, spread);
	q.push_back (root_glob);
	
	//make an sxl 2d vector for glob coordinates, spread is width, level is depth
	int s; int l;
	TwoDArray<T>* tda = new TwoDArray<T>(20, 20, def);
	int spread_middle = 10;
	
	//begin level order traversal of BST and insert into tda
	Node<T>* curr_node;
	while (!(q.empty())) {
		Glob<T>* curr_glob = q.front();
		curr_node = curr_glob->getNodePointer();
		if (curr_node->getLeftChild()!=0) {
			//get level, spread for left node and make a glob
			level = (curr_glob->getLevel())+2;
			spread = (curr_glob->getSpread())-2;
			Glob<T>* new_glob_left = new Glob<T>(*(curr_node->getLeftChild()), level, spread);
			q.push_back (new_glob_left);
			//insert left leg into tda
			tda->insert(level-1, spread_middle+spread+1, leftLeg);
		}
		if (curr_node->getRightChild()!=0) {
			level=(curr_glob->getLevel())+2;
			spread = (curr_glob->getSpread())+2;
			Glob<T>* new_glob_right = new Glob<T>(*(curr_node->getRightChild()), level, spread);
			q.push_back (new_glob_right);
			//insert right leg tda
			tda->insert(level-1, spread_middle+spread-1, rightLeg);			
		}		
		if (curr_node!=0) {
			l = curr_glob->getLevel();
			s = curr_glob->getSpread();
			//cout << "Adding " << curr_glob->getNodePointer()->getValue() << "at " << spread_middle+s << + "," << l << endl;
			tda->insert(l, spread_middle+s, curr_glob->getNodePointer()->getValue());
		}
		q.pop_front();	
	}
	tda->print();
	delete tda;
	delete root_glob;
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
