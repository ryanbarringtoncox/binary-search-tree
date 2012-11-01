#include "Node.h"
#include "Glob.h"
#include <string>
#include <iostream>
using std::endl;
using std::cout;

using std::string;


int main() {
  Node<string>* ns = new Node<string>(string("hello world!"));
  Node<int>* ni = new Node<int>(5);
  Node<double>* nd = new Node<double>(3.1459);

  std::cout << ns->getValue()<< std::endl;
  std::cout << ni->getValue()<< std::endl;
  std::cout << nd->getValue()<< std::endl;

  Glob<int>* g = new Glob<int>(*ni, 0, -8);
	
  cout << "Glob pointer has value " << ((g->getNodePointer())->getValue()) << endl;
  cout << "Has level of " << g->getLevel() << endl;
  cout << "Has spread of " << g->getSpread() << endl;
	
  return 0;
}
