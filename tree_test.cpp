#include "BST.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(5);
  bst->insert(6);
  bst->insert(3);
  bst->insert(2);
  bst->insert(7);
  bst->insert(12);
  bst->insert(4);
	
  bst->visualPrint();

  /*bst->print();

  cout << "Removing 5" << endl;
  bst->remove(5);
  cout << "Removing 6" << endl;
  bst->remove(6);
  //cout << "Removing 13" << endl;
  //bst->remove(13);
  cout << "Removing 12" << endl;
  bst->remove(12);
  //cout << "Is 50 in tree?" << endl;
  //bst->remove(50);
  //cout << "Is 2 in tree?" << endl;
  //bst->remove(2);
  cout << "Removing 2" << endl;
  bst->remove(2);	
	
  bst->print();
   
  */
	
}
