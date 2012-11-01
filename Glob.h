#ifndef __GLOB_H__
#define __GLOB_H__

#include <string>
#include "Node.h"

//A glob has a node pointer and an associated level, used for printing BST
template <typename T>
class Glob {
private:
	Node<T>* n;
	int level;
	
public:
	Glob<T>(Node<T>& nodePointer, int l);
	//~Glob<T>();
	
	Node<T>*& getNodePointer();
	int getLevel();
};


#endif
