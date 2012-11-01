#include "Glob.h"
#include <iostream>
#include <list>
using namespace std;
using std::cout;
using std::endl;

template <typename T>
Glob<T>::Glob(Node<T>& nodePointer, int l) {
	n = &nodePointer;
	level = l;
}

/*template <typename T>
Glob<T>::~Glob() {
	
}
*/

template <typename T>
Node<T>*& Glob<T>::getNodePointer() {
	return n;
}


template <typename T>
int Glob<T>::getLevel() {
	return level;
}

template class Glob<int>;
template class Glob<double>;
template class Glob<std::string>;