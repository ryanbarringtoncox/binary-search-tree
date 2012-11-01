#include "BST.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {
  
  BST<std::string>* s = new BST<std::string>();
	
  s->insert("mop");
  s->insert("kid");
  s->insert("org");
  s->insert("ole");
  s->insert("bed");
  s->insert("orr");
  s->insert("toe");
  s->insert("zoo");
  s->insert("ape");
  s->insert("abe");
  s->insert("bic");
  s->insert("sow");	
		
  s->visualPrint("   ");

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
